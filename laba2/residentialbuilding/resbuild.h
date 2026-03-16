#pragma once

#include "..\building\building.h"

class ResBuilding : public Building {
 private:
    int room_count_;
    bool have_sewerage_;
 public:
    ResBuilding();
    ResBuilding(int, bool);
    ResBuilding(int, int, int);
    ResBuilding(int, int, int, int, bool);
    ResBuilding(ResBuilding&);
    ~ResBuilding();
    int getRoomCount();
    bool isSewerage();
    void setRoomCount(int);
    void setSewerage(bool);
};