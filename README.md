# Simulation de piétons en environnement fermé      


Initialement créé dans le cadre du projet 3BIM, INSA-LYON, 2015-2016

L. Becquey - A. Cathignol - N. Mauvisseau - M. Simon

# Installation
## Dépendances
Vous avez besoin de la bibliothèque SFML ( http://www.sfml-dev.org/index-fr.php )
- Sur Ubuntu, Linux Mint, Debian: `sudo apt-get install libsfml-dev`
- Sur Fedora: `sudo dnf install SFML` (Attention, rediriger manuellement les include de SFML vers /usr/include sur Fedora :/ )
- Sur Mac: `brew install sfml`

## Compilation
Puis, depuis un terminal, lancez:
```
mkdir obj
make
```

# Exécution:

Depuis un terminal, lancez:

- Par défaut: `./escape default`
- Ou, si vous voulez charger un batiment personnalisé: `./escape 'path/to/building/plan.bmp'` 
- Ou, si vous souhaitez en plus régler vous même les paramètres: `./escape 'path/to/building/plan.bmp' Npiétons modèle  VitesseLimite  mood  show_graphics show_limits`
- Pour choisir les paramètres via un prompt : `./escape`

```
  'path/to/building/plan.bmp'       ==>    Lien vers une image plan de batiment
  Npiétons                          ==>    Le nombre d'individus à simuler dans ce batiment
  modèle                            ==>    La façon dont les piétons gèrent les obstacles
            1 = Les piétons attendent derrière les obstacles
            2 = Les piétons se décalent de l'obstacle le plus proche
            3 = Les piétons se décalent de la moyenne des positions des obstacles
  VitesseLimite                     ==>    Vitesse Limite moyenne des piétons (en m/s)
  mood                              ==>    Etat de stress de la population (0=calme, 1=stressée)
  show_graphics                     ==>    1 pour afficher la simulation, 0 pour faire les calculs
  show_limits (si show_graphics=1)  ==>    1 pour afficher les limites de zone, 0 sinon
  
Dans tous les cas, lance ./escape sans argument vous proposera de les préciser à la main.
```

# Description du modèle
https://www.overleaf.com/5401940bstyqz#/17178647/
