#include "markup_frontend/frameview.h"
#include <QPushButton>
#include <QGridLayout>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "markup_frontend/scaledbox.h"

FrameView::FrameView(QWidget *parent) :
        QGraphicsView (parent) {}

FrameView::~FrameView() {}

void FrameView::mousePressEvent(QMouseEvent *event) {}
void FrameView::mouseReleaseEvent(QMouseEvent *event) {}
void FrameView::keyPressEvent(QKeyEvent *event) {}

void FrameView::paintEvent(QPaintEvent *event) {
    // возможно, что эта логика избыточна и её можно заменить более простой
    if (!image.isNull()) {
        scene = new QGraphicsScene(this); // object defined in header
        this->setScene(scene);
        scene->addPixmap(image);
        QPen pen(Qt::green, 10, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

        for (auto iter = markup.begin(); iter != markup.end(); ++iter) {
            scene->addRect(iter->getScaledRect(scene->width(), scene->height()), pen);
        }

        this->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
    }
    QGraphicsView::paintEvent(event);
}

void FrameView::loadimagebypath(QString path) {
    image = QPixmap(path);
    QPaintEvent *event = new QPaintEvent(QRect());
    paintEvent(event);
}

void FrameView::slot_set_markup(QMap<int, ScaledBBox> newmarkup) {
    markup.clear();
    QMap<int, ScaledBBox>::const_iterator iter = newmarkup.constBegin();
    while (iter != newmarkup.constEnd()) {
        markup.add(iter.key(), iter.value());
        ++iter;
    }
}
