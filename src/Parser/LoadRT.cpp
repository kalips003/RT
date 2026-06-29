// #include "Parser.hpp"

// #include <fstream>
// #include <iostream>

// ///////////////////////////////////////////////////////////////////////////////]
// #include <unordered_set>
// #include <vector>

// typedef std::vector<TokenLine>  tokens;
// ///////////////////////////////////////////////////////////////////////////////]
// bool Parser::loadRT(const std::string& file, Scene& scene) {

//     std::ifstream RTfile(file);
//     if (!RTfile.is_open()) {
//         std::cout << C_542 "error opening: (" RED << file << C_542 ")" RESET << std::endl;
//         return false;
//     }
//     tokens t = preParsingFile(RTfile);

//     for (std::vector<TokenLine>::iterator it = t.begin(); it != t.end(); ++it)
//         parseOneObject(scene, *it);

//     return true;
// }

// // #include "LightSource.hpp"
// // #include "AmbientLight.hpp"
// // #include "Camera.hpp"
// // #include "Sphere.hpp"
// ///////////////////////////////////////////////////////////////////////////////]
// void parseOneObject(Scene& scene, const TokenLine& t)
// {
//     if (t.objectType == "camera")
//         scene.add(Camera(t));
//     else if (t.objectType == "light")
//         scene.add(Light(t));
//     else if (t.objectType == "ambient")
//         scene.add(AmbientLight(t));
//     else if (t.objectType == "sphere")
//         scene.add(std::make_unique<Sphere>(t));

// }

// ///////////////////////////////////////////////////////////////////////////////]
// tokens preParsingFile(std::ifstream& file)
// {
//     tokens rtrn;
//     std::string line;

//     static const std::unordered_set<std::string> objectTypes = {
//         "camera","ambient","light","circle","sphere","plane",
//         "cylinder","cone","hyperboloid","paraboloid",
//         "arrow","cube","sprite","object"
//     };

//     TokenLine* current = nullptr;

//     while (std::getline(file, line))
//     {
//         if (line.empty() || line[0] == '#')
//             continue;

//         bool indented = std::isspace(line[0]);

//         std::istringstream ss(line);

//         // NEW OBJECT
//         if (!indented) {
        
//             std::string first;
//             ss >> first;
//             first = toLower(first);

//             if (!objectTypes.count(first)) {
//                 std::cout << C_542 "bad objectTypes: (" RED << first << C_542 ")" RESET << std::endl;
//                 continue;
//             }

//             rtrn.push_back(TokenLine());
//             current = &rtrn.back();
//             current->objectType = first;
//         }

//         // KV LINE
//         if (!current)
//             continue;

//         std::string token;
//         while (ss >> token)
//             h_read_kv(*current, token);
//     }

//     return rtrn;
// }

// ///////////////////////////////////////////////////////////////////////////////]
// void    h_read_kv(TokenLine& to_fill, const std::string& token) {

//     size_t eq = token.find('=');
//     if (eq == std::string::npos || token.size() < 2) {
//         std::cout << C_542 "bad token: (" RED << token << C_542 ")" RESET << std::endl;
//         return;
//     }
    
//     std::string key = toLower(token.substr(0, eq));
//     std::string value = token.substr(eq + 1);
//     to_fill.kv[key] = value;
// }

// #include <algorithm>
// std::string toLower(std::string s)
// {
//     std::transform(s.begin(), s.end(), s.begin(),
//                    [](unsigned char c){ return std::tolower(c); });
//     return s;
// }