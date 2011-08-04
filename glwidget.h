/*
 * This code was created by Jeff Molofee 1999
 * And ported to C++/Qt4 by Wesley Stessens 2009
 *
 * Contact Jeff through his website: http://nehe.gamedev.net/
 * Contact Wesley for port-specific comments: wesley@ubuntu.com
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "Bmp.h"
#include <math.h>

#define PI 3.14159265
struct Vector {
    float x, y, z;
};

class GLWidget : public QGLWidget {
    Q_OBJECT

public:
    GLWidget();
    ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    //void keyPressEvent(QKeyEvent *event);
    //void changeEvent(QEvent *event);
    void setCamera(float posX, float posY, float posZ, float targetX, float targetY, float targetZ);
    void setMouseLeft(bool flag) { mouseLeftDown = flag; };
    void setMouseRight(bool flag) { mouseRightDown = flag; };
    void setMousePosition(int x, int y) { mouseX = x; mouseY = y; };
    void setDrawMode(int mode);
    void animate(bool flag) { animateFlag = flag; };

    void rotateCamera(int x, int y);
    void zoomCamera(int dist);

    void setBackgroundRed(float value);             // change background colour
    void setBackgroundGreen(float value);
    void setBackgroundBlue(float value);

private:
    // member functions
    void initLights();                              // add a white light ti scene
    unsigned int createEarthDL();
    unsigned int loadTextureBmp(const char *filename);

    // members
    QPoint lastPos;
    int windowWidth;
    int windowHeight;
    bool animateFlag;                               // on/off animation
    bool changeDrawMode;
    int drawMode;
    unsigned int listId;                            // display list ID
    bool mouseLeftDown;
    bool mouseRightDown;
    int mouseX;
    int mouseY;
    float cameraAngleX;
    float cameraAngleY;
    float cameraDistance;
    float bgColor[4];
    bool bgFlag;
    unsigned char* frameBuffer;                     // framebuffer to store RGBA color
    int bufferSize;
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
    QPointF pixelPosToViewPos(const QPointF&);
    float rotX, rotY, autoRotX, autoRotY, scaleAll;
    float angleX, angleY;
    void lonLat2Point(float , float , Vector *);
};

#endif // GLWIDGET_H
