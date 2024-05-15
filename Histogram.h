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
