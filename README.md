# OptionPricingPP
Personal Project for Option Pricing

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

