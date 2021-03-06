
/*! \file color.cpp
    \brief Functions for managing colour.
*/
#include "color.hpp"

namespace blit {

  /**
   * Convert a colour from the Hue, Saturation, Value colour space to Red, Green, Blue, Alpha.
   * Alpha will always be set to 255.
   *
   * \param[in] h Hue from 0.0 to 1.0.
   * \param[in] s Saturation from 0.0 to 1.0.
   * \param[in] v Value from 0.0 to 1.0.
   * \return RGBA colour.
   */
  rgba hsv_to_rgba(float h, float s, float v) {
    rgba res(0, 0, 0, 255);

    uint8_t i = uint8_t(h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch (i % 6) {
    case 0: res = rgba(v, t, p); break;
    case 1: res = rgba(q, v, p); break;
    case 2: res = rgba(p, v, t); break;
    case 3: res = rgba(p, q, v); break;
    case 4: res = rgba(t, p, v); break;
    case 5: res = rgba(v, p, q); break;
    }

    return res;
  }

}  