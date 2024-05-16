/**
 * Histogram class tracks min, max and mode of added EInteger values.
 *
 * getMode, getMinValue and getMaxValue member functions will return false
 * values if no values are added.
 * Min, max and mode are initialized to Four, Zero and Zero EInteger values
 * respectively.
 *
 * If there are more than one EInteger values that appear same number of times
 * in the material, the first one that reached the number will be returned by
 * getMode function.
 *
 */
#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "HistogramBase.h"

#include "Log.h"
#include <memory>
class Histogram : public Hist::HistogramBase {
public:
  Histogram(std::unique_ptr<Logger> l);
  Histogram(const Histogram &h) = default;
  Histogram(Histogram &&h) = default;
  ~Histogram() = default;

  void add(Hist::EInteger e) override;
  Hist::EInteger getMode() const override;
  Hist::EInteger getMinValue() const override;
  Hist::EInteger getMaxValue() const override;

private:
  std::map<Hist::EInteger, int> m_his;
  Hist::EInteger m_min;
  Hist::EInteger m_max;
  Hist::EInteger m_mode;
};

#endif // HISTOGRAM_H
