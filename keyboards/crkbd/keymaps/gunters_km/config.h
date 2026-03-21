#pragma once

// -- Timing für Home Row Mods ----------------------------------------------
// TAPPING_TERM: Haltezeit in ms, ab der ein Tap-Hold-Key als Hold gilt.
// 250ms ist konservativ — lieber etwas langsamer als Fehlauslösungen.
#define TAPPING_TERM 250

// -- CHORDAL_HOLD ----------------------------------------------------------
// Modifier wird nur erkannt wenn der zweite Tastendruck auf der ANDEREN
// Hand liegt. Verhindert ß-statt-ls und ähnliche Fehlauslösungen.
#define CHORDAL_HOLD

// -- PERMISSIVE_HOLD -------------------------------------------------------
// Wenn du einen Tap-Hold-Key hältst und innerhalb des TAPPING_TERM einen
// zweiten Key drückst UND loslässt, wird der erste Key als Hold gewertet.
// Macht Modifier+Key-Combos reaktionsschneller.
#define PERMISSIVE_HOLD
