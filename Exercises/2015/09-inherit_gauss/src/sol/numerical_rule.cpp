#include "numerical_rule.hpp"

namespace NumericalIntegration
{

  // Costructor
  QuadratureRule::QuadratureRule():
    M_w     (),
    M_n     (),
    M_exactDegree ( 0 )
  {} // Costructor

  // Virtual destructor.
  QuadratureRule::~QuadratureRule()
  {} // Virtual destructor.

  // Costructor
  Simpson::Simpson()
  {
    M_exactDegree = 3;

    M_w.reserve ( 3 );
    M_n.reserve ( 3 );

    // Fill the weights.
    M_w.push_back(1./3);
    M_w.push_back(4./3);
    M_w.push_back(1./3);

    // Fill the nodes.
    M_n.push_back(-1.0);
    M_n.push_back(0.0);
    M_n.push_back(1.0);
  } // Costructor

  // Costructor
  MidPoint::MidPoint()
  {
    M_exactDegree = 1;

    M_w.reserve ( 1 );
    M_n.reserve ( 1 );

    // Fill the weight.
    M_w.push_back(2.0);

    // Fill the node.
    M_n.push_back(0.0);
  } // Costructor

  // Costructor
  Gauss4Pt::Gauss4Pt()
  {
    M_exactDegree = 5;

    M_w.reserve ( 4 );
    M_n.reserve ( 4 );

    // Fill the weights
    M_w.push_back(1./6.);
    M_w.push_back(5./6.);
    M_w.push_back(5./6.);
    M_w.push_back(1./6.);

    // Fill the nodes.
    M_n.push_back(-1.);
    M_n.push_back(-std::sqrt(5.)/5.);
    M_n.push_back(std::sqrt(5.)/5.);
    M_n.push_back(1.);

  } // Costructor

} // namespace NumericalIntegration
