#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct Song {
    string name;
    string artist;
    int duration;
    string album;
    string genre;
};

struct Playlist {
    string name;
    list<Song> songs;
};

class User {
public:
    string username;
    bool isPremium;
    Playlist currentPlaylist;

    User(const string &name, bool premium) : username(name), isPremium(premium) {}

    void saveCurrentPlaylist() {
        ofstream file("usuarios/" + username + ".txt");
        if (!file) {
            cerr << "Error al abrir el archivo de usuario." << endl;
            exit(1);
        }

        for (const auto &song : currentPlaylist.songs) {
            file << song.name << '|' << song.artist << '|' << song.duration
                 << '|' << song.album << '|' << song.genre << '\n';
        }

        file.close();
    }

    void loadCurrentPlaylist() {
        ifstream file("usuarios/" + username + ".txt");
        if (!file) {
            cerr << "Error al abrir el archivo de usuario." << endl;
            exit(1);
        }

        string line;

        while (getline(file, line)) {
            Song song;
            istringstream iss(line);
            getline(iss, song.name, '|');
            getline(iss, song.artist, '|');
            iss >> song.duration;
            getline(iss, song.album, '|');
            getline(iss, song.genre);

            currentPlaylist.songs.push_back(song);
        }

        file.close();
    }
};

class MusicPlayer {
private:
    list<Playlist> playlists;
    list<User> users;
    User* currentUser;

public:
    MusicPlayer() : currentUser(nullptr) {
        loadPlaylists();
        loadUsers();
    }

    ~MusicPlayer() {
        if (currentUser != nullptr) {
            currentUser->saveCurrentPlaylist();
        }
    }

    void loadPlaylists() {
        ifstream file("playlist.txt");
        if (!file) {
            cerr << "Error al abrir el archivo de playlists." << endl;
            exit(1);
        }

        string line;
        Playlist currentPlaylist;

        while (getline(file, line)) {
            if (line.empty()) {
                playlists.push_back(currentPlaylist);
                currentPlaylist = Playlist();
            } else {
                Song song;
                istringstream iss(line);
                getline(iss, song.name, '|');
                getline(iss, song.artist, '|');
                iss >> song.duration;
                getline(iss, song.album, '|');
                getline(iss, song.genre);

                currentPlaylist.songs.push_back(song);
            }
        }

        file.close();
    }

    void savePlaylists() {
        ofstream file("playlist.txt");
        if (!file) {
            cerr << "Error al abrir el archivo de playlists." << endl;
            exit(1);
        }

        for (const auto &playlist : playlists) {
            for (const auto &song : playlist.songs) {
                file << song.name << '|' << song.artist << '|' << song.duration
                     << '|' << song.album << '|' << song.genre << '\n';
            }
            file << '\n';  // Separador entre playlists
        }

        file.close();
    }

    void loadUsers() {
        ifstream file("usuarios/usuarios.txt");
        if (!file) {
            cerr << "Error al abrir el archivo de usuarios." << endl;
            exit(1);
        }

        string line;

        while (getline(file, line)) {
            string username;
            bool isPremium;

            istringstream iss(line);
            iss >> username >> isPremium;

            users.push_back(User(username, isPremium));
        }

        file.close();
    }

    void saveUsers() {
        ofstream file("usuarios/usuarios.txt");
        if (!file) {
            cerr << "Error al abrir el archivo de usuarios." << endl;
            exit(1);
        }

        for (const auto &user : users) {
            file << user.username << ' ' << user.isPremium << '\n';
        }

        file.close();
    }

    User* getUser(const string &username) {
        auto it = find_if(users.begin(), users.end(), [&](const User &u) {
            return u.username == username;
        });

        if (it != users.end()) {
            return &(*it);
        } else {
            return nullptr;
        }
    }

    void login() {
        string username;
        cout << "Ingrese su nombre de usuario: ";
        getline(cin, username);

        currentUser = getUser(username);

        if (currentUser == nullptr) {
            bool isPremium;
            cout << "¿Es usted un usuario Premium? (1 para sí, 0 para no): ";
            cin >> isPremium;
            cin.ignore();  // Consumir el salto de línea

            users.push_back(User(username, isPremium));
            currentUser = &users.back();
            saveUsers();
        }

        currentUser->loadCurrentPlaylist();
    }

    void logout() {
        if (currentUser != nullptr) {
            currentUser->saveCurrentPlaylist();
            currentUser = nullptr;
        }
    }

    void playCurrentPlaylist(bool shuffle) {
        if (currentUser != nullptr && !currentUser->currentPlaylist.songs.empty()) {
            if (shuffle) {
                // Shuffle the playlist
                list<Song> shuffledSongs(currentUser->currentPlaylist.songs.begin(), currentUser->currentPlaylist.songs.end());
                shuffledSongs.sort([](const Song&, const Song&) { return rand() < RAND_MAX / 2; });

                currentUser->currentPlaylist.songs.assign(shuffledSongs.begin(), shuffledSongs.end());
            }

            cout << "Reproduciendo playlist: " << currentUser->currentPlaylist.name << '\n';

            for (const auto &song : currentUser->currentPlaylist.songs) {
                cout << "Reproduciendo: " << song.name << " - " << song.artist << " ("
                     << song.duration << "s) [Playlist: " << currentUser->currentPlaylist.name << "]\n";
            }

            cout << "Playlist terminada.\n";
        } else {
            cout << "No hay canciones disponibles en la playlist actual.\n";
        }
    }

    void updatePlan() {
        if (currentUser != nullptr) {
            if (currentUser->isPremium) {
                cout << "Usted ya es un usuario Premium.\n";
            } else {
                currentUser->isPremium = true;
                cout << "¡Felicidades! Ahora es un usuario Premium.\n";
                saveUsers();
            }
        } else {
            cout << "Debe iniciar sesión primero.\n";
        }
    }

    void createPlaylist() {
        if (currentUser != nullptr && currentUser->isPremium) {
            Playlist newPlaylist;
            cout << "Ingrese el nombre de la nueva playlist: ";
            getline(cin, newPlaylist.name);

            string input;
            do {
                Song song;
                cout << "Ingrese el nombre de la canción (o 'fin' para finalizar): ";
                getline(cin, input);

                if (input != "fin") {
                    song.name = input;

                    cout << "Ingrese el nombre del artista: ";
                    getline(cin, song.artist);

                    cout << "Ingrese la duración en segundos: ";
                    cin >> song.duration;
                    cin.ignore();  // Consumir el salto de línea

                    cout << "Ingrese el nombre del álbum: ";
                    getline(cin, song.album);

                    cout << "Ingrese el género de la canción: ";
                    getline(cin, song.genre);

                    newPlaylist.songs.push_back(song);
                }
            } while (input != "fin");

            playlists.push_back(newPlaylist);
            savePlaylists();
        } else {
            cout << "Solo los usuarios Premium pueden crear playlists.\n";
        }
    }
};

int main() {
    srand(time(nullptr));  // Semilla para shuffle

    MusicPlayer player;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\n=== Menú ===\n";
        cout << "1. Iniciar sesión\n";
        cout << "2. Reproducir playlist\n";
        cout << "3. Actualizar plan\n";
        cout << "4. Cerrar sesión\n";
        cout << "5. Salir\n";

        int choice;
        cout << "Ingrese su elección: ";
        cin >> choice;
        cin.ignore();  // Consumir el salto de línea

        switch (choice) {
            case 1:
                player.login();
                break;
            case 2:
                player.playCurrentPlaylist(true);  // La reproducción aleatoria es ahora la opción predeterminada
                break;
            case 3:
                player.updatePlan();
                break;
            case 4:
                player.logout();
                cout << "Sesión cerrada.\n";
                break;
            case 5:
                cout << "Saliendo del reproductor...\n";
                exitProgram = true;
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese un número válido.\n";
        }
    }

    return 0;
}
