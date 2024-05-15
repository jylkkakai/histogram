#ifndef HISTOGRAM_CPP
#define HISTOGRAM_CPP

#include "Histogram.h"
#include "HistogramBase.h"
#include "Log.h"
#include <memory>

Histogram::Histogram(std::unique_ptr<Logger> l)
    : Hist::HistogramBase::HistogramBase(std::move(l)) {

  m_min = Hist::Four;
  m_max = Hist::Zero;
  m_mode = Hist::Zero;
  for (int i = Hist::Zero; i <= Hist::Four; i++) {
    m_his[static_cast<Hist::EInteger>(i)] = 0;
  }
}

void Histogram::add(Hist::EInteger e) {
  m_his[e]++;
  std::cout << m_his[e] << " " << m_his[m_mode] << std::endl;
  if (m_his[e] > m_his[m_mode])
    m_mode = e;
  if (e < m_min)
    m_min = e;
  if (e > m_max)
    m_max = e;
}
Hist::EInteger Histogram::getMode() const { return m_mode; }
Hist::EInteger Histogram::getMinValue() const { return m_min; }
Hist::EInteger Histogram::getMaxValue() const { return m_max; }

#endif // HISTOGRAM_CPP
