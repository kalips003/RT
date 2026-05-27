class AmbientLight {
public:
    AmbientLight() = default;

    AmbientLight(const TokenLine& t)
    {
        // ratio + color (parse later from kv)
    }

public:
    double ratio = 0.1;
    Vec3 color = {1,1,1};
};