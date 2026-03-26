# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Was ist das

QMK-Keymap fuer ein **Corne rev4.1 standard** (Keebart, RP2040) mit Extra-Spalten (`LAYOUT_split_3x6_3_ex2`). Miryoku-Stil mit eigenen Anpassungen. Alle Antworten auf Deutsch.

## Build

```bash
# Lokal (QMK CLI muss installiert sein)
make crkbd/rev4_1/standard:gunters_km

# CI: Push triggert GitHub Actions Workflow automatisch
# Artifact "corne-firmware" enthaelt die .uf2-Datei
```

Der CI-Build nutzt `SKIP_GIT=yes` wegen fehlender Git-Tags im Container.

## Flashen (RP2040)

Bootloader-Taste (Q links, P rechts) gedrueckt halten, USB einstecken, `.uf2` auf das erscheinende RPI-RP2-Laufwerk ziehen. Beide Haelften einzeln flashen.

## Architektur

- **keymap.c** -- Komplettes Layout (7 Layer: BASE, NAV, SYM1, SYM2, NUM, FUN, EURKEY). Nur `LAYOUT_split_3x6_3_ex2`, kein Fallback. Die ASCII-Diagramme ueber jedem Layer sind die kanonische Dokumentation.
- **config.h** -- Timing/Verhalten: `TAPPING_TERM 250`, `CHORDAL_HOLD`, `PERMISSIVE_HOLD`.
- **rules.mk** -- Build-Flags: `CAPS_WORD_ENABLE`.
- **DESIGN.md** -- Design-Entscheidungen, Layer-Diagramme, offene Ideen.
- **keymap.c.bak** -- Backup der alten 4-Layer-Keymap vor dem Miryoku-Umbau.

## Design-Prinzipien

- **Miryoku-Stil**: Alle 6 Daumen sind LT (Tap + Hold). Kein reines Miryoku -- SYM aufgeteilt, Mouse/Media-Layer weggelassen.
- **GACS Home Row Mods** (GUI-Alt-Ctrl-Shift von aussen nach innen). `CHORDAL_HOLD` ist zwingend noetig.
- **Layer-Logik**: Linker Daumen haelt Layer -> Inhalt rechts, Modifier links. Rechter Daumen haelt Layer -> Inhalt links, Modifier rechts.
- **Symmetrische Klammern**: Gleicher Finger fuer zusammengehoerige Paare (( ) auf Index, { } auf Mittel, etc.).
- **= _ - auf Daumen beider SYM-Layer**: Immer erreichbar, egal welcher Layer aktiv.
- **Esc ist eine eigene Taste** (Home-Row links + Tap auf NAV-Daumen).
- **Extra-Spalten** (ex2) nur fuer Media-Keys (Vol, Mute, Play), auf allen Layern transparent.
- **EURKEY-Layer** fuer Umlaute (ae oe ue ss Euro + grosse Umlaute), statt AltGr auf dem Daumen.
- Vial wurde bewusst entfernt -- inkompatibel mit Standard-QMK.
