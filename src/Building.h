#ifndef Building_h
#define Building_h

#include "Pedest.h"
#include <SFML/Window.hpp>
#include <math.h>
#include <fstream>

using namespace std;
using namespace sf;

class Building
{
public:
  // =========================== Static attributes =====================

  static int NPEDEST;
  static int ZOOM;
  static int SHOWWALLS;
  static double RANDOM_WEIGHT;

  // =========================== Constructors ==========================

  Building(const string &filename);

  // =========================== Destructor ============================

  ~Building();

  // =========================== Getters ===============================

  inline int length() const;
  inline int width() const;
  inline int *map() const;
  inline int map(size_t x, size_t y) const;
  inline vector<RectangleShape> walls() const;
  inline Pedest people(const int i) const;

  // =========================== Public Methods ========================

  void movePeople(void);
  void studyPeople(unsigned int time);
  bool notEmpty(void) const;
  void drawData(int *map, int w, int l) const;
  void drawMap(int *map, int w, int l) const;

protected:
  //======================== Private Methods ===========================

  vector<pair<int, int>> findExit(const pair<int, int> &start, int *map, int W, int H);
  unsigned int getDirection(double x, double y);

  //======================== Attributes =================================
  int length_; // hauteur de l'image (en cases ou pixels)
  int width_;  // largeur de l'image (en cases ou pixels)
  int *map_;
  int *will_tab;
  vector<RectangleShape> walls_;
  vector<float> xborders_;
  vector<float> yborders_;
  Pedest *people_;
  vector<int> gone_;
};

//========================Inline functions' definition==================

inline int Building::length() const { return length_; }
inline int Building::width() const { return width_; }
inline int *Building::map() const { return map_; }
inline int Building::map(size_t x, size_t y) const { return map_[width_ * y + x]; }
inline vector<RectangleShape> Building::walls() const { return walls_; }
inline Pedest Building::people(const int i) const { return people_[i]; }

#endif /* Building_h */
