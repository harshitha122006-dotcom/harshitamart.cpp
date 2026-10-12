#include <winsock2.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string readHTML() {
    ifstream file("index.html");
    if (!file) return "<h1>HARSHI MART</h1>";

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET server = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(server, (sockaddr*)&address, sizeof(address));
    listen(server, 10);

    cout << "================================\n";
    cout << "      HARSHI MART BACKEND\n";
    cout << "================================\n";
    cout << "Server: http://localhost:8080\n";
    cout << "Products API: /api/products\n";
    cout << "Login API: /api/login\n";
    cout << "Register API: /api/register\n";
    cout << "================================\n";

    while (true) {
        SOCKET client = accept(server, nullptr, nullptr);

        char buffer[4096] = {};
        recv(client, buffer, sizeof(buffer) - 1, 0);

        string request(buffer);
        string body;

        if (request.find("GET /api/products") != string::npos) {
            body =
                "["
                "{\"id\":1,\"name\":\"Laptop\",\"price\":57000},"
                "{\"id\":2,\"name\":\"Mouse\",\"price\":800},"
                "{\"id\":3,\"name\":\"Keyboard\",\"price\":1200},"
                "{\"id\":4,\"name\":\"Headphones\",\"price\":1800},"
                "{\"id\":5,\"name\":\"Smart Watch\",\"price\":2500},"
                "{\"id\":6,\"name\":\"Backpack\",\"price\":1500},"
                "{\"id\":7,\"name\":\"Shoes\",\"price\":2200},"
                "{\"id\":8,\"name\":\"Kurti\",\"price\":1500},"
                "{\"id\":9,\"name\":\"T-Shirt\",\"price\":900},"
                "{\"id\":10,\"name\":\"Sunglasses\",\"price\":700}"
                "]";
        }
        else if (request.find("POST /api/login") != string::npos) {
            body = "{\"status\":\"success\",\"message\":\"Login successful\"}";
        }
        else if (request.find("POST /api/register") != string::npos) {
            body = "{\"status\":\"success\",\"message\":\"Registration successful\"}";
        }
        else {
            body = readHTML();
        }

        string type = request.find("/api/") != string::npos
                    ? "application/json"
                    : "text/html";

        string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: " + type + "\r\n"
            "Access-Control-Allow-Origin: *\r\n"
            "Content-Length: " + to_string(body.size()) +
            "\r\nConnection: close\r\n\r\n" + body;

        send(client, response.c_str(), response.size(), 0);
        closesocket(client);
    }

    closesocket(server);
    WSACleanup();

    return 0;
}