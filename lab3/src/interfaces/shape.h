#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include <QString>
#include <QFile>

class Shape {
 public:
    Shape() : center_(QPoint(0, 0)), select_(false), color_(QColor::fromRgb(153, 255, 204)) {};
    Shape(QPoint center, QRect canvas_border, bool select, QColor color = QColor::fromRgb(153, 255, 204)) : center_(center), select_(select), canvas_border_(canvas_border), color_(color) {};
    virtual ~Shape() {
        //qDebug() << "delete base shape";
    }
    virtual bool isSelected() {
        return select_;
    }
    virtual void setSelect(bool select) {
        select_ = select;
    }
    void setCenter(QPoint point) {
        center_ = point;
    }
    virtual void setColor(QColor color) {
        color_ = color;
    }
    void setCanvasBorser(QRect canvas_border) {
        canvas_border_ = canvas_border;
        returnInCanvas();
    }
    QColor getColor() {
        return color_;
    }
    QRect getBorder() {
        return border_;
    }
    virtual void draw(QPainter& painter) {
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QBrush(color_, Qt::SolidPattern));
        //qDebug() << select_;
        if (!select_) {
            
            painter.setPen(QColor::fromRgb(0, 204, 102));
            //qDebug() << "Hello rect";
        } else {
            if (!in_group) drawResizeRect(painter);
            painter.setPen(QColor::fromRgb(0, 0, 204));
            //qDebug() << "Hello ctrl rect";
        }
    }
    virtual bool hit(QPoint const) = 0;
    virtual void move(int dx, int dy) {
        //qDebug() << "shape move" << dx << dy;
        center_ = QPoint(center_.x() + dx, center_.y() + dy);
    }
    virtual void updateShape() = 0;
    virtual void resize(int) = 0;
    virtual bool isPositiveLenght() = 0;
    virtual void save(QTextStream&) = 0;
    virtual void load(QStringList& line) {
        center_ = QPoint(line[1].toInt(), line[2].toInt());
        canvas_border_ = QRect(line[3].toInt(), line[4].toInt(), line[5].toInt(), line[6].toInt());
        color_ = line[line.size() - 1];
    };
    virtual QString type() = 0;
    virtual QString getDataForFile() {
        return QString("%1 %2 %3 %4 %5 %6 %7")
        .arg(type())
        .arg(center_.x())
        .arg(center_.y())
        .arg(canvas_border_.x())
        .arg(canvas_border_.y())
        .arg(canvas_border_.width())
        .arg(canvas_border_.height());
    };

    void print() {
        qDebug() << "tri" << center_;
    }

    bool isValid() {
        //qDebug() << canvas_border_.contains(border_) << border_ << canvas_border_;
        return canvas_border_.contains(border_);
    }

    void returnInCanvas() {
        int dx = 0;
        int dy = 0;

        if (border_.x() < 0) {
            dx = - border_.x();
        }
        if (border_.y() < 0) {
            dy = - border_.y();
        }

        if (border_.x() + border_.width() > canvas_border_.x() + canvas_border_.width()) {
            //qDebug() << border_.x() + border_.width() << canvas_border_.x() + canvas_border_.width() << (border_.x() + border_.width()) - (canvas_border_.x() + canvas_border_.width());
            dx = (canvas_border_.x() + canvas_border_.width()) - (border_.x() + border_.width());
        }
        if (border_.y() + border_.height() > canvas_border_.y() + canvas_border_.height()) {
            dy = (canvas_border_.y() + canvas_border_.height()) - (border_.y() + border_.height());
        }
        //qDebug() << "asdasdasda" << dx << dy << border_.x() << border_.y();
        //qDebug() << center_;
        move(dx, dy);
        updateShape();
        //qDebug() << center_;
    }

    virtual bool isGroup() {
        return false;
    }

    void drawResizeRect(QPainter& painter) {
        QRect rect = getResizeRect();
        auto brush = painter.brush();
        painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        painter.setPen(Qt::NoPen);
        painter.drawRect(rect);
        painter.setBrush(brush);
    }

    QRect getResizeRect() {
        return QRect(border_.x(), border_.y(), -8, -8);
    }

    void setInGroup(bool b) {
        in_group = b;
    }

 protected:
    QPoint center_;
    bool select_;
    QColor color_;
    QRect canvas_border_;
    QRect border_;
    bool in_group = false;
};