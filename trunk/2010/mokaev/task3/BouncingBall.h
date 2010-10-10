#ifndef _BOUNCING_BALL_H_
#define _BOUNCING_BALL_H_

#include<QWidget>
#include<QEvent>
#include<QPaintEvent>
#include<QTimer>

class BallWidget : public QWidget{
	Q_OBJECT;
public:
	BallWidget( QWidget* parent = NULL, int radius = 0, int velocityX = 0, int velocityY = 0 );
public:
	void setRadius( const int& radius );
	void setVelosity( const int& velocityX, const int& velocityY );
private:
	void paintEvent( QPaintEvent* );
	void timerEvent( QTimerEvent* timerEvent );
private:
	int myX, myY;
	int myVelocityX, myVelocityY;
	int myRadius;
	int myCurrRadiusX, myCurrRadiusY;
	int myHeight, myWidth;
	bool isKicked;
	int myTimerId;

};

#endif
