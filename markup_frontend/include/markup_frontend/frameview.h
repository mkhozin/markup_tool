#ifndef FRAMEVIEW_H
#define FRAMEVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QPushButton>
#include "framemarkup.h"

class FrameView : public QGraphicsView
{
    // Q_OBJECT

public:
    explicit FrameView(QWidget* parent = nullptr);
    ~FrameView();

    void setScaledPixmap(const QPixmap &pixmap);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap image;
    FrameMarkup markup;
    QGraphicsScene *scene = nullptr;
};

#endif // FRAMEVIEW_H
