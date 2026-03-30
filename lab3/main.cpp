#include <QApplication>
#include "./canvas/canvas.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    CanvasWidget canvas;
    canvas.show();
    return app.exec();
}