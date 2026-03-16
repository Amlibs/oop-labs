#pragma once 

class Build {
 private:
    int width_;
    int height_;
 public:
    Build();
    Build(Build&);
    Build(int, int);
    ~Build();
    void setWidth(int);
    void setHeight(int);
    int getWidth();
    int getHeight();
};