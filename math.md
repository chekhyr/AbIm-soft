Density distribution in MOT: 

$n(x,y,z)=n_0\exp(-\frac{x^2}{2w_x^2})\exp(-\frac{y^2}{2w_y^2})\exp(-\frac{z^2}{2w_z^2})$ — where $n_0$ is the peak density

Considering axial symmetry:

$w_x = w_z$

Total number of atoms in MOT:

$\iiint^{+\infty}_{-\infty}n(x,y,z)dx dy dz=N$

$\iiint^{+\infty}_{-\infty}n_0\exp(-\frac{x^2}{2w_x^2})\exp(-\frac{y^2}{2w_y^2})\exp(-\frac{z^2}{2w_x^2})dx dy dz=(2\pi)^{3/2}n_0 w_x^2 w_y = N$

$n_0=\frac{N}{(2\pi)^{3/2} w_x^2 w_y}$

Therefore,

$n(x,y,z)=\frac{N}{(2\pi)^{3/2} w_x^2 w_y}\exp(-\frac{x^2}{2w_x^2})\exp(-\frac{y^2}{2w_y^2})\exp(-\frac{z^2}{2w_x^2})$

$n_2(x,y)=\int^{+\infty}_{-\infty}n(x,y,z)dz=\frac{N}{2\pi w_x w_y}\exp(-\frac{x^2}{2w_x^2})\exp(-\frac{y^2}{2w_y^2})$

$n(x,y,z)=\frac{n_2(x,y)}{\sqrt{2\pi} w_x}\exp(-\frac{z^2}{2w_x^2}) $

Beer–Bouguer–Lambert's law:

$I(x,y)=I_0(x,y)\exp{(-od(x,y))}$

$\exp{(-od(x,y))}=\frac{I(x,y)}{I_0(x,y)}:=T(x,y)$ — 2D transmission

Optical density:

$od(x,y)=-\ln{T(x,y)}$

$od(x,y)=\sigma n_2(x,y)$, where $\sigma$ is a photon absorption cross-section of the transition

Therefore:

$n_2(x,y)=\frac{-\ln{T(x,y)}}{\sigma}$

At the center $(x,y)=(0,0)$ :

$\sqrt{2\pi} w_x n_0 = n_2(0,0) = \frac{-\ln{T(0,0)}}{\sigma}$


Therefore,

$n_0=-\frac{\ln{T(0,0)}}{\sqrt{2\pi}w_x \sigma }$

Number of atoms:

$N=-\frac{2\pi w_x w_y}{\sigma} \ln{T(0,0)}$

Also, note that $w_x=\frac{FWHM_x}{2\sqrt{2\ln{2}}}=0.42466\cdot FWHM_x$

$\sqrt{2\pi}\cdot 0.42466\approx1.0645$

Therefore:

$n_0\approx-\frac{\ln{T}}{FWHM_x \sigma }$