# PixelViewer

Projet expérimental en C utilisant **SDL2** pour explorer le rendu de **pixels
via des tableaux mémoire**, sans aucun calcul complexe par GPU.

---

## Objectif

Afficher et manipuler des pixels dans un espace vidéo SDL, en vue de créer des
**formes visuelles**, sans passer par un moteur de rendu ou des bibliothèques
graphiques avancées.

Ce projet sert de **prototype graphique** pour un futur système plus bas niveau
avec un **noyau minimal**.

---

## Philosophie

- 💡 Aucun calcul lourd ou transformation complexe à ce stade.
- 📦 Tous les pixels sont stockés et manipulés directement dans des
                                         **tableaux de type `uint32_t`**.
- 🖼️ SDL est utilisé uniquement comme **interface de sortie vidéo**.

---

## Dépendances

- SDL2 (`libsdl2-dev` sous Ubuntu)

---

## Compilation (exemple)

```bash
gcc -Iinclude src/*.c -o pixel_viewer `sdl2-config --cflags --libs`
```
---

## Détail technique

- Un tableau `pixels[]` de type `uint32_t` contient l’ensemble
   des pixels de l’image à l’écran.
- Chaque pixel est codé sur 32 bits : `0xAARRGGBB` (alpha, rouge, vert, bleu).
- Ce tableau est transféré à une texture SDL (`SDL_Texture*`)
   à chaque frame via `SDL_UpdateTexture()`.
- L’image est ensuite affichée avec `SDL_RenderCopy()`
   suivi de `SDL_RenderPresent()`.

Ce système permet un contrôle total et direct sur chaque pixel, idéal pour
expérimenter des motifs visuels et des effets graphiques simples.

---

## À venir

- Un effet de pixels évolutif ou animé
- Une base pour un environnement graphique bare metal ou embarqué

---

## License
JM
Projet libre – fais-en ce que tu veux, mais cite l’auteur si tu t’en inspires.
