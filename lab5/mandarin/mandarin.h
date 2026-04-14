#pragma once

#include "../fruit/fruit.h"

class Mandarin : public Fruit {
 public:
    Mandarin();
    virtual ~Mandarin();
    void splashJuice() {
        magic_wand_ += "magic";
        std::cout << "mandarin splash" << '\n';
    }
    std::string classname() {
        return "mandarin";
    }
    bool isA(std::string name) {
        return name == "mandarin" || Fruit::isA(name);
    }
 private:
    std::string magic_wand_ = "wand";
};