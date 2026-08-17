# Cub3D

Projet 42 : un petit moteur de ray-casting en C, inspiré de Wolfenstein 3D. Le programme prend en entrée un fichier `.cub` qui décrit une carte, et affiche une vue en pseudo-3D avec un personnage déplaçable au clavier.

Le rendu utilise la MiniLibX fournie par 42, et une libft persos pour les fonctions de base.

## Fonctionnalités

- Parsing du fichier `.cub` (textures, couleurs, carte)
- Ray-casting pour le rendu des murs
- 4 textures différentes selon le mur regardé (nord/sud/est/ouest)
- Couleurs de sol et plafond configurables
- Déplacement et rotation du joueur
- Collisions avec les murs
- Vérifications sur la carte (fermée, spawn valide, caractères autorisés...)

## Prérequis

Linux, avec les libs X11 :

```bash
sudo apt install libx11-dev libxext-dev
```

## Compilation

```bash
git clone <url-du-repo>
cd Cub3d
make
```

Le Makefile compile la libft et la MiniLibX avant de build l'exécutable.

```bash
make clean   # objets
make fclean  # + exécutable et libs
make re      # fclean + all
```

## Lancer le jeu

```bash
./cub3d map.cub
```

## Contrôles

- W / S : avancer / reculer
- A / D : strafe gauche / droite
- Flèches gauche / droite : tourner la caméra
- Échap : quitter

<img width="800" height="437" alt="2026-08-1711-37-21-ezgif com-crop" src="https://github.com/user-attachments/assets/84e51b67-d68a-480e-968d-aed9daa35634" />

## Format du fichier .cub

```
NO ./textures/no.xpm
SO ./textures/so.xpm
EA ./textures/ea.xpm
WE ./textures/we.xpm

F 159,69,19
C 119,136,153

111111111111111111111111
100000000000000000000001
100000000110000000000001
1000000000N0000000000001
100000000000000000000001
111111111111111111111111
```

- NO / SO / EA / WE : chemins des textures des 4 murs
- F : couleur du sol en R,G,B
- C : couleur du plafond en R,G,B
- Carte : 1 = mur, 0 = case vide, N/S/E/W = position et orientation de départ du joueur, espace = vide hors zone jouable

La carte doit être fermée par des murs, sinon erreur au lancement.

## Structure

```
cub3d.c        point d'entrée, boucle et gestion des touches
parsing.c      lecture/validation du fichier .cub
read_map.c     lecture de la carte
check_map.c    vérification de la carte
get_colors.c   parsing des couleurs
get_textures.c parsing des textures
wall.c / wall_utils.c   ray-casting
put_texture.c  application des textures
player.c       position initiale
direction.c    orientation
moove.c        déplacements et collisions
error_parsing.c gestion des erreurs
cub3d_h/       header
libft/         libft
mlx/           MiniLibX
textures/      textures par défaut
map.cub        carte d'exemple
```

## Erreurs gérées

Nombre d'arguments, extension du fichier, textures/couleurs manquantes ou invalides, carte non fermée, spawn absent ou en double, caractères invalides dans la carte.
