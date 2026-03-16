#pragma once 

class Building {
 private:
   int width_;
   int height_;
   int length_;
 public:
   Building();
   Building(Building&);
   Building(int, int, int);
   ~Building();
   void setWidth(int);
   void setHeight(int);
   void setLength(int);
   int getWidth();
   int getHeight();
   int getLength();
};