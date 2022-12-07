
Pour pallier ce problème, il faut prendre en compte la distance obtenue sur ce-dit plan virtuel (voir Figure 8).
Plutôt que de tourner nos vecteurs et donc d'obtenir des distances différentes entre eux, nous allons les créer directement avec une distance constante entre eux.
Il faut donc diviser la distance D par le nombre de rayons (W) pour obtenir l’espace exact identique entre chaque rayon.
Pour obtenir cette distance D, nous devons préalablement calculer la distance O (moitié de D).
Celle-ci se calcule grâce à la trigonométrie (voir triangle rectangle de droite dans la figure 8).
Nous connaissons l’angle ɑ qui est la moitié du FOV et qui mesure donc FOV / 2 radians, ainsi que la longueur du côté adjacent qui est de 1.
Nous cherchons la longueur du côté opposé (O).
Nous avons donc l'équation suivante :
𝑡𝑎𝑛(ɑ) = 𝑂/1 ⇔𝑡𝑎𝑛(𝐹𝑂𝑉/2) = 𝑂. Ainsi : O = tan(FOV / 2). Or D = 2 * O
donc D = 2 * tan(FOV / 2).
On peut ensuite définir R_H, le ratio horizontal (la distance entre les vecteurs sur l’axe horizontal) entre chaque rayon.
Nous avons donc: R_H = D / W donc R_H = 2 * tan(FOV / 2) / W (dans l’exemple, R_H ≃ 0.29).
Le ratio vertical R_V se calcule grâce à FOV_V, le FOV vertical proportionnel au FOV horizontal. On a FOV_V = FOV * H / W donc
R_V = 2 * tan(FOV_V / 2) / H = 2 * tan(FOV * H / W / 2) / H
donc R_V = 2 * tan(FOV * H / (W * 2)) / H.



