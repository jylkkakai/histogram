#ifndef RANDOMEINTEGERGENERATOR_CPP
#define RANDOMEINTEGERGENERATOR_CPP
#include <chrono>
#include <random>

#include "HistogramBase.h"
#include "RandomEintegerGenerator.h"

RandomEintegerGenerator::RandomEintegerGenerator() {

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  RandomEintegerGenerator::m_generator = std::default_random_engine(seed);
  RandomEintegerGenerator::m_distribution =
      std::uniform_int_distribution<int>(Hist::Zero, Hist::Four);
}

Hist::EInteger RandomEintegerGenerator::operator()() {
  return static_cast<Hist::EInteger>(m_distribution(m_generator));
}
#endif // !RANDOMEINTEGERGENERATOR_CPP
