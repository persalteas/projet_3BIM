//=========================== Includes =================================

#include "Pedest.h"

using namespace std;

//================= Definition of static attributes ====================

double Pedest::MOOD = 0;
double Pedest::RMAX = 12; // 60cm de rayon
double Pedest::RMIN = 8;  // 40cm de rayon
double Pedest::EQSPEEDMIN = 1;
double Pedest::EQSPEEDMAX = 3;
int Pedest::MODEL = 3;
double Pedest::ZONE_XMIN = 0;
double Pedest::ZONE_XMAX = 0;
double Pedest::ZONE_YMIN = 0;
double Pedest::ZONE_YMAX = 0;

//=========================== Constructors =============================

Pedest::Pedest()
{
  x_ = 0;
  y_ = 0;
  radius_ = 0;
  mood_ = 0;
  img_ = CircleShape();
  speed_ = 0;
  eq_speed_ = 0;
  is_out = false;
}

Pedest::Pedest(const int startX, const int startY, int zoom)
{
  x_ = startX;
  y_ = startY;
  unsigned int r = rand() % (int)(Pedest::RMAX - Pedest::RMIN) + Pedest::RMIN;
  radius_ = (float)r;
  mood_ = 0;
  img_ = CircleShape(r);
  img_.setPosition(zoom * x_ - r, zoom * y_ - r);
  img_.setFillColor(Color(Color::Green));
  speed_ = 0;
  eq_speed_ = 0.5 * ((double)(rand() % (int)(10 * (Pedest::EQSPEEDMAX - Pedest::EQSPEEDMIN)) + 10 * Pedest::EQSPEEDMIN));
  is_out = false;
}

void Pedest::operator=(const Pedest &model)
{
  x_ = model.x_;
  y_ = model.y_;
  radius_ = model.radius_;
  mood_ = model.mood_;
  img_ = model.img_;
  speed_ = model.speed_;
  eq_speed_ = model.eq_speed_;
  is_out = false;
}

//=========================== Public Methods ===========================

void Pedest::move(double x_move, double y_move, double new_speed, int zoom, int w, int l)
{
  x_ += x_move;
  y_ += y_move;
  img_.setPosition(zoom * x_ - radius_, zoom * y_ - radius_);
  speed_ = new_speed;
  if (x_ > w + 2 or x_ < -2 or y_ < -2 or y_ > l + 2)
    is_out = true;
}
