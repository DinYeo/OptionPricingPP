# OptionPricingPP
Personal Project for Option Pricing

# Link to Project Plan
https://www.notion.so/Pricing-Engines-208fe221867480699c16ce47e897dba3?source=copy_link

# Black Scholes Model
$$V = \phi[Se^{-q(T-t)}N(\phi d_1)-Xe^{-r(T-t)}N(\phi d_2)]$$

where
- $\phi$ = 1 for a call option and -1 for a put option
- $q$ - continuous annual dividend rate
- $r$ - the continuous annual risk-free interest rate
- $\sigma$ - the annual volatility
- N(x) - standard normal CDF
#
- d1 - expected good case, normalised
- N(d1) - probability of d1
- d2 - expected bad case, normalised
- N(d2) - probability of d2
$$d1 = \frac{\log{\frac{s}{x} + (r-q+\frac{1}{2}\sigma^2)(T-t)}}{\sigma \sqrt{T-t}}$$
$$d2 = d1 - \sigma\sqrt{T-t}$$
![Calculation of d1](image.png)
![d2 in PDF](image-1.png)
#
### Calculating the price of a Call Option
$$C(S_0,t) = S_0N(d_1) - Ke^{-r(T-t)}N(d_2)$$
$S_0N(d_1)$ represents the RETURN = Stock Price * Probability Function

$Ke^{-r(T-t)}N(d_2)$ represents the COST = Strike Price * Discount to 
Present Value * Probability Function
#

## Delta of the Option
##### Non-dividend paying stock
$\Delta_{call} = N(d_1)$
##### Stock w continuous dividend yield
$\Delta_{call} = e^{-\delta T}N(d_1)$

$e^{-\delta T}$
- discount factor for the dividends, price depreciates by the dividend yield over time
- underlying asset's price is adjusted by the present value of future dividends

## Gamma of the Option