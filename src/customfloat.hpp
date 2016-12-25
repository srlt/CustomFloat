/**
 * @file   customfloat.hpp
 * @author Sébastien Rouault <sebmsg@free.fr>
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * any later version. Please see https://gnu.org/licenses/gpl.html
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * @section DESCRIPTION
 *
 * A simple, customizable floating-point number implementation.
**/

#pragma once
// ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▁ Headers ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔

// External headers
#include <cmath>

// ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔ Headers ▔
// ▁ Exceptions ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔

namespace CustomFloat {
namespace Exception {

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

/** Defines an exception.
 * @param name   Exception name
 * @param parent Parent exception (use ::std::exception as the root)
 * @param text   Explanatory string
**/
#define EXCEPTION(name, parent, text) \
    class name: public parent { \
    public: \
        /** Return the explanatory string. \
         * @return Explanatory string \
        **/ \
        virtual char const* what() const noexcept { \
            return "customfloat: " text; \
        } \
    }

/** Exceptions tree.
**/
EXCEPTION(Any, ::std::exception, "exception");
    EXCEPTION(Overflow, Any, "overflow");

#undef EXCEPTION

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

}
}

// ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔ Exceptions ▔
// ▁ Helpers ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔

namespace CustomFloat {

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

/** Natural and signed integer types.
**/
using nat_t = uint_fast32_t;
using int_t =  int_fast32_t;

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

/** Unsigned integer type selector.
 * @param size Type size required, in bits
 * @return Type Smallest integer type large enough
**/
template<nat_t size> class Uint final {
    static_assert(size <= 64, "'size' is too large");
public:
    using Type =
        typename ::std::conditional<size <= 8, uint8_t,
        typename ::std::conditional<size <= 16, uint16_t,
        typename ::std::conditional<size <= 32, uint32_t,
        uint64_t>::type>::type>::type;
};

/** Selection helper.
**/
template<nat_t size> using uint_t = typename Uint<size>::Type;

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

/** Natural integer fast power.
 * @param a
 * @param b
 * @retrun a^b (with 0^0 == 1)
*/
static constexpr nat_t static_pow(nat_t a, nat_t b) {
    if (b == 0)
        return 1;
    nat_t r = static_pow(a, b >> 1);
    if (b & 1)
        return r * r * a;
    return r * r;
}

/** Integer rounded division.
 * @param a
 * @param b
 * @retrun round(a / b)
*/
static constexpr int_t static_div(int_t a, nat_t b) {
    if (a < 0) {
        return (a - (b >> 1)) / b;
    } else {
        return (a + (b >> 1)) / b;
    }
}

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

}

// ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔ Helpers ▔
// ▁ Custom floating-point value ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔

namespace CustomFloat {

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

/** Custom floating-point type.
 * @param m_size Mantissa size (in bits)
 * @param e_size Exponent size (in bits)
 * @param base   Base for the exponent (optional)
 * @param bias   Negative bias for the exponent (optional)
**/
template<nat_t m_size, nat_t e_size, nat_t base = 2, nat_t bias = static_pow(2, e_size - 1)> class Float final {
    static_assert(m_size > 0, "Invalid mantissa size");
    static_assert(e_size > 0, "Invalid exponent size");
    static_assert(base > 1, "Invalid base");
private:
    /** Current class instance.
    **/
    using This = Float<m_size, e_size, base, bias>;
    /** Underlying data structure (/!\ actual bitfield layout is implementation defined).
    **/
    class Data final {
    public:
        uint8_t sign: 1; // Sign
        uint_t<m_size> mantissa: m_size; // Mantissa
        uint_t<e_size> exponent: e_size; // Power of base exponent
    };
public:
    static constexpr nat_t limit = static_pow(base, static_pow(2, e_size) - bias); // Maximal storable value
private:
    Data data; // Floating-point number
private:
    /** "Over-precise" types.
    **/
    using over_val_t = double;       // Floating-point number
    using over_int_t = int_fast32_t; // Signed integer
    /** Floating-point conversion and update.
     * @param nb Convert this number
    **/
    template<class Type> void convert(Type nb) {
        bool negative;
        if (nb == 0) {
            data.sign = 0;
            data.mantissa = 0;
            data.exponent = 0;
            return;
        } else if (nb < 0) {
            negative = true;
            nb = -nb;
        } else {
            negative = false;
        }
        // Conversion stage
        over_val_t const val_val  = static_cast<over_val_t>(nb);
        over_val_t const val_base = static_cast<over_val_t>(base);
        over_val_t const val_exp = ::std::floor(::std::log2(val_val) / ::std::log2(val_base));
        over_int_t int_man = static_cast<over_int_t>(::std::round((val_val / ::std::pow(val_base, val_exp) - static_cast<over_val_t>(1)) / static_cast<over_val_t>(base - 1) * static_cast<over_val_t>(static_pow(2, m_size))));
        over_int_t int_exp = static_cast<over_int_t>(val_exp) + static_cast<over_int_t>(bias);
        if (int_man < 0) { // Underflow
            int_man = 0;
        } else if (int_man >= static_pow(2, m_size)) { // Local overflow
            int_man = 0;
            int_exp++;
        }
        if (int_exp < 0) { // Underflow
            int_exp = 0;
        } else if (int_exp >= static_pow(2, e_size)) { // Overflow
            throw Exception::Overflow();
        }
        // Update stage
        data.sign = (negative ? 1 : 0);
        data.mantissa = int_man;
        data.exponent = int_exp;
    }
public:
    /** Null constructor.
    **/
    Float(): Float(0) {}
    /** Floating-point constructor/assignment.
     * @param val Floating-point to convert
    **/
    template<class Type> Float(Type val) {
        convert(val);
    }
    template<class Type> This& operator=(Type val) {
        convert(val);
        return *this;
    }
    /** Copy constructor/assignment.
     * @param nb Number to copy
     * @return Current object
    **/
    Float(This const& nb): data(nb.data) {}
    This& operator=(This const& nb) {
        data = nb.data;
        return *this;
    }
    /** Floating-point conversion.
     * @return Value converted
    **/
    template<class Type> operator Type() const {
        over_val_t val_exp = static_cast<over_val_t>(data.exponent) - static_cast<over_val_t>(bias);
        return (data.sign == 0 ? 1 : -1) * (static_cast<over_val_t>(data.mantissa) * static_cast<over_val_t>(base - 1) / static_cast<over_val_t>(static_pow(2, m_size)) + static_cast<over_val_t>(1)) * ::std::pow(static_cast<over_val_t>(base), val_exp);
    }
private:
    /** Addition component.
     * @param a Biggest absolute value
     * @param b Smallest absolute value
     * @return a + b, does not set sign
    **/
    static Data sum(Data const& a, Data const& b) {
        Data r;
        nat_t p = static_pow(base, a.exponent - b.exponent);
        nat_t m = static_div(static_cast<nat_t>(a.mantissa) * p + static_cast<nat_t>(b.mantissa) + static_pow(2, m_size) / (base - 1), p);
        nat_t e = a.exponent;
        while (m >= static_pow(2, m_size)) { // Local overflow
            e++;
            m = static_div(m - static_pow(2, m_size), base);
        }
        if (e >= static_pow(2, e_size)) // Overflow
            throw Exception::Overflow();
        r.mantissa = m;
        r.exponent = e;
        return r;
    }
    /** Substraction component.
     * @param a Biggest absolute value
     * @param b Smallest absolute value
     * @return a - b, does not set sign
    **/
    static Data diff(Data const& a, Data const& b) {
        Data r;
        nat_t p = static_pow(base, a.exponent - b.exponent);
        int_t m = static_div(static_cast<int_t>(a.mantissa) * p - static_cast<int_t>(b.mantissa) - static_pow(2, m_size) / (base - 1), p);
        nat_t e = a.exponent;
        while (m < 0) { // Local underflow
            if (e == 0) { // Underflow
                r.mantissa = 0;
                r.exponent = 0;
                return r;
            }
            e--;
            m = (m + static_pow(2, m_size)) * base; /// FIXME: Not the correct formula ?
        }
        r.mantissa = m;
        r.exponent = e;
        return r;
    }
public:
    /** Negation.
     * @return -this
    **/
    This operator-() const {
        This res;
        res.data = data;
        res.data.sign = ~res.data.sign;
        return res;
    }
    /** Addition.
     * @param x Number to add
     * @return this + x
    **/
    This operator+(This const& x) const {
        This res;
        auto const& op = (data.sign != x.data.sign ? diff : sum);
        if (x.data.exponent > data.exponent || (x.data.exponent == data.exponent && x.data.mantissa > data.mantissa)) { // x > this
            res.data = op(x.data, data);
            res.data.sign = x.data.sign;
        } else { // x <= this
            res.data = op(data, x.data);
            res.data.sign = data.sign;
        }
        return res;
    }
};
static_assert(::std::is_standard_layout<Float<1, 1>>::value, "'Float' class template does not instanciate standard layout classes");

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

}

// ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔ Custom floating-point value ▔
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
