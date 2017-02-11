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
#include <type_traits>

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
template<nat_t m_size, nat_t e_size, nat_t base = 2, nat_t bias = static_pow(2, e_size - 1)> class Float {
    static_assert(m_size > 0, "Invalid mantissa size");
    static_assert(e_size > 0, "Invalid exponent size");
    static_assert(base > 1, "Invalid base");
public:
    static constexpr nat_t limit = static_pow(base, static_pow(2, e_size) - bias); // Maximal storable value
protected:
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
protected:
    Data data; // Floating-point number
protected:
    /** "Over-precise" types.
    **/
    using over_val_t = double;       // Floating-point number
    using over_int_t = int_fast32_t; // Signed integer
protected:
    /** Integer round division.
     * @param a
     * @param b (must be > 0)
     * @retrun round(a / b)
    */
    static constexpr over_int_t static_div(over_int_t a, over_int_t b) {
        if (a < 0) {
            return (a - (b / 2)) / b;
        } else {
            return (a + (b / 2)) / b;
        }
    }
    /** Floating-point/integral conversion and update.
     * @param nb Convert this number
    **/
    template<class Type, class = typename ::std::enable_if<::std::is_integral<Type>::value || ::std::is_floating_point<Type>::value>::type> void convert(Type const& nb) {
        if (nb == 0) {
            data.sign = 0;
            data.mantissa = 0;
            data.exponent = 0;
            return;
        }
        // Conversion stage
        over_val_t const val_val  = static_cast<over_val_t>(nb < 0 ? -nb : nb);
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
        data.sign = (nb < 0 ? 1 : 0);
        data.mantissa = int_man;
        data.exponent = int_exp;
    }
    template<nat_t other_m_size, nat_t other_e_size, nat_t other_base, nat_t other_bias> void convert(Float<other_m_size, other_e_size, other_base, other_bias> const& nb) {
        convert(static_cast<long double const&>(*this)); // Conversion through high-precision float
    }
public:
    /** Null constructor.
    **/
    Float(): Float(0) {}
    /** Copy constructor/assignment.
     * @param nb Number to copy
     * @return Current object
    **/
    Float(This const& nb): data(nb.data) {}
    This& operator=(This const& nb) {
        data = nb.data;
        return *this;
    }
    /** Floating-point constructor/assignment.
     * @param val Floating-point to convert
     * @return Current object
    **/
    template<class Type, class = typename ::std::enable_if<!::std::is_same<Type, This>::value>::type> Float(Type const& val) {
        convert(val);
    }
    template<class Type, class = typename ::std::enable_if<!::std::is_same<Type, This>::value>::type> This& operator=(Type const& val) {
        convert(val);
        return *this;
    }
    /** Floating-point/integral conversion.
     * @return Value converted
    **/
    template<class Type, class = typename ::std::enable_if<::std::is_integral<Type>::value || ::std::is_floating_point<Type>::value>::type> operator Type() const {
        over_val_t val_exp = static_cast<over_val_t>(data.exponent) - static_cast<over_val_t>(bias);
        return (data.sign == 0 ? 1 : -1) * (static_cast<over_val_t>(data.mantissa) * static_cast<over_val_t>(base - 1) / static_cast<over_val_t>(static_pow(2, m_size)) + static_cast<over_val_t>(1)) * ::std::pow(static_cast<over_val_t>(base), val_exp);
    }
protected:
    /** Addition component.
     * @param a Biggest absolute value
     * @param b Smallest absolute value
     * @return a + b, does not set sign
    **/
    static Data sum(Data const& a, Data const& b) {
        nat_t delta = static_cast<nat_t>(a.exponent) - static_cast<nat_t>(b.exponent);
        if (delta > m_size) // 'b' has no impact (sufficient condition)
            return a;
        over_int_t p = static_pow(base, delta);
        over_int_t m = static_div((static_cast<over_int_t>(a.mantissa) * p + static_cast<over_int_t>(b.mantissa)) * static_cast<over_int_t>(base - 1) + static_pow(2, m_size), static_cast<over_int_t>(base - 1) * p);
        over_int_t e = a.exponent;
        while (m >= static_pow(2, m_size)) { // Local overflow
            e++;
            m = static_div(m - static_pow(2, m_size), base);
        }
        if (e >= static_pow(2, e_size)) // Overflow
            throw Exception::Overflow();
        Data r;
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
        nat_t delta = static_cast<nat_t>(a.exponent) - static_cast<nat_t>(b.exponent);
        if (delta > m_size) // 'b' has no impact (sufficient condition)
            return a;
        over_int_t p = static_pow(base, delta);
        over_int_t m = static_div((static_cast<over_int_t>(a.mantissa) * p - static_cast<over_int_t>(b.mantissa)) * static_cast<over_int_t>(base - 1) - static_pow(2, m_size), static_cast<over_int_t>(base - 1) * p);
        over_int_t e = a.exponent;
        while (m < 0) { // Local underflow
            if (e == 0) { // Underflow
                Data r;
                r.mantissa = 0;
                r.exponent = 0;
                return r;
            }
            e--;
            m = m * static_cast<over_int_t>(base) + static_pow(2, m_size);
        }
        Data r;
        r.mantissa = m;
        r.exponent = e;
        return r;
    }
    /** Multiplication component.
     * @param a Absolute value
     * @param b Absolute value
     * @return a * b, does not set sign
    **/
    static Data mult(Data const& a, Data const& b) {
        if ((a.mantissa == 0 && a.exponent == 0) || (b.mantissa == 0 && b.exponent == 0)) { // Trivial case
            Data r;
            r.mantissa = 0;
            r.exponent = 0;
            return r;
        }
        over_int_t m = static_div(static_cast<over_int_t>(a.mantissa) * static_cast<over_int_t>(b.mantissa) * static_cast<over_int_t>(base - 1) + (static_cast<over_int_t>(a.mantissa) + static_cast<over_int_t>(b.mantissa)) * static_pow(2, m_size), static_pow(2, m_size));
        over_int_t e = static_cast<over_int_t>(a.exponent) + static_cast<over_int_t>(b.exponent) - static_cast<over_int_t>(bias);
        while (m >= static_pow(2, m_size)) { // Local overflow
            e++;
            m = static_div(m - static_pow(2, m_size), base);
        }
        if (e >= static_pow(2, e_size)) // Overflow
            throw Exception::Overflow();
        Data r;
        r.mantissa = m;
        r.exponent = e;
        return r;
    }
    /** Division component.
     * @param a Absolute value
     * @param b Absolute value
     * @return a / b, does not set sign
    **/
    static Data div(Data const& a, Data const& b) {
        if (a.mantissa == 0 && a.exponent == 0) { // Trivial case
            Data r;
            r.mantissa = 0;
            r.exponent = 0;
            return r;
        }
        over_int_t e = static_cast<over_int_t>(a.exponent) - static_cast<over_int_t>(b.exponent) + bias;
        if (e < 0) { // Underflow
            Data r;
            r.mantissa = 0;
            r.exponent = 0;
            return r;
        }
        over_int_t m = static_div((static_cast<over_int_t>(a.mantissa) - static_cast<over_int_t>(b.mantissa)) * static_pow(2, m_size), static_cast<over_int_t>(b.mantissa) * static_cast<over_int_t>(base - 1) + static_pow(2, m_size));
        while (m < 0) { // Local underflow
            if (e == 0) { // Underflow
                Data r;
                r.mantissa = 0;
                r.exponent = 0;
                return r;
            }
            e--;
            m = m * static_cast<over_int_t>(base) + static_pow(2, m_size);
        }
        Data r;
        r.mantissa = m;
        r.exponent = e;
        return r;
    }
public:
    /** Comparisons operators.
     * @param x Value to compare
     * @return Result of the comparison
    **/
    bool operator==(This const& x) const {
        return x.data.sign == data.sign && x.data.mantissa == data.mantissa && x.data.exponent == data.exponent;
    }
    bool operator!=(This const& x) const {
        return !(*this == x);
    }
    bool operator<(This const& x) const {
        if (x.data.sign != data.sign)
            return x.data.sign < data.sign;
        if (data.sign == 0) // Positive numbers
            return x.data.exponent > data.exponent || (x.data.exponent == data.exponent && x.data.mantissa > data.mantissa);
        return x.data.exponent < data.exponent || (x.data.exponent == data.exponent && x.data.mantissa < data.mantissa);
    }
    bool operator<=(This const& x) const {
        return (*this < x) || (*this == x);
    }
    bool operator>(This const& x) const {
        return !(*this <= x);
    }
    bool operator>=(This const& x) const {
        return !(*this < x);
    }
public:
    /** Negation.
     * @return -this
    **/
    This operator-() const {
        This res;
        res.data = data;
        res.data.sign = 1 - res.data.sign;
        return res;
    }
    /** Addition.
     * @param x Number to add
     * @return this + x
    **/
    This operator+(This const& x) const {
        This res;
        auto const& op = (data.sign != x.data.sign ? diff : sum);
        if (x.data.exponent > data.exponent || (x.data.exponent == data.exponent && x.data.mantissa > data.mantissa)) { // |x| > |this|
            res.data = op(x.data, data);
            res.data.sign = x.data.sign;
        } else { // |x| <= |this|
            res.data = op(data, x.data);
            res.data.sign = data.sign;
        }
        return res;
    }
    This& operator+=(This const& x) {
        auto const& op = (data.sign != x.data.sign ? diff : sum);
        if (x.data.exponent > data.exponent || (x.data.exponent == data.exponent && x.data.mantissa > data.mantissa)) { // |x| > |this|
            data = op(x.data, data);
            data.sign = x.data.sign;
        } else { // |x| <= |this|
            auto sign = data.sign;
            data = op(data, x.data);
            data.sign = sign;
        }
        return *this;
    }
    /** Substraction.
     * @param x Number to substract
     * @return this - x
    **/
    This operator-(This const& x) const {
        This res;
        auto const& op = (data.sign == x.data.sign ? diff : sum);
        if (x.data.exponent > data.exponent || (x.data.exponent == data.exponent && x.data.mantissa > data.mantissa)) { // |x| > |this|
            res.data = op(x.data, data);
            res.data.sign = 1 - x.data.sign;
        } else { // |x| <= |this|
            res.data = op(data, x.data);
            res.data.sign = data.sign;
        }
        return res;
    }
    This& operator-=(This const& x) {
        auto const& op = (data.sign == x.data.sign ? diff : sum);
        if (x.data.exponent > data.exponent || (x.data.exponent == data.exponent && x.data.mantissa > data.mantissa)) { // |x| > |this|
            data = op(x.data, data);
            data.sign = 1 - x.data.sign;
        } else { // |x| <= |this|
            auto sign = data.sign;
            data = op(data, x.data);
            data.sign = sign;
        }
        return *this;
    }
    /** Multiplication.
     * @param x Number to multiply
     * @return this * x
    **/
    This operator*(This const& x) const {
        This res;
        res.data = mult(data, x.data);
        res.data.sign = (data.sign == x.data.sign ? 0 : 1);
        return res;
    }
    This& operator*=(This const& x) {
        auto sign = (data.sign == x.data.sign ? 0 : 1);
        data = mult(data, x.data);
        data.sign = sign;
        return *this;
    }
    /** Division.
     * @param x Number to multiply
     * @return this / x
    **/
    This operator/(This const& x) const {
        This res;
        res.data = div(data, x.data);
        res.data.sign = (data.sign == x.data.sign ? 0 : 1);
        return res;
    }
    This& operator/=(This const& x) {
        auto sign = (data.sign == x.data.sign ? 0 : 1);
        data = div(data, x.data);
        data.sign = sign;
        return *this;
    }
};
static_assert(::std::is_standard_layout<Float<1, 1>>::value, "'Float' class template does not instanciate standard layout classes");

// ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

}

// ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔ Custom floating-point value ▔
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
