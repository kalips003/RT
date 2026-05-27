#include <cstdint>

struct Color {
    double a = 1.0;
    double r = 1.0;
    double g = 1.0;
    double b = 1.0;
};

struct Point3 {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

struct Vec3 {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

///////////////////////////////////////////////////////////////////////////////]
struct TokenLine {
    std::string objectType;              // "circle", "sphere"
    std::unordered_map<std::string, std::string> kv; // size=<value>
};
typedef std::vector<TokenLine>  tokens;
