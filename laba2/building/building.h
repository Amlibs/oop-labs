#pragma once 

class Building {
 protected:
  int width_;
  int height_;
  int length_;
 public:
  Building();
  Building(const Building&);
  Building(int, int, int);
  ~Building();
  void setWidth(int);
  void setHeight(int);
  void setLength(int);
  int getWidth();
  int getHeight();
  int getLength();
  int getSquare();
};