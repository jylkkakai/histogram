#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H
#include "Histogram.h"
#include <random>
class RandomEintegerGenerator : public Hist::RandomEintegerGeneratorBase {
public:
  RandomEintegerGenerator();
  Hist::EInteger operator()();

private:
  std::default_random_engine m_generator;
  std::uniform_int_distribution<int> m_distribution;
};

#endif // !RANDOMEINTEGERGENERATOR_H
