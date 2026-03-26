# Gunters Corne Keymap

Keymap für **Corne rev4.1 standard** (Keebart, RP2040) mit Extra-Spalten (`LAYOUT_split_3x6_3_ex2`).

## Layout-Übersicht

4 Layer: BASE, NAV, SYM, NUM. Kein Schnickschnack.

```
BASE — QWERTY mit Home Row Mods
┌──────────────────────────────────────────────────────────────────────┐
│ Hyp  Q    W    E    R    T   Vol- Vol+  Y    U    I    O    P  Del  │
│ Esc  A/G  S/A  D/C  F/S  G   Mute Play  H    J/S  K/C  L/A  ;/G ' │
│ Sft  Z    X    C    V    B              N    M    ,    .    /  Sft  │
│                NAV  Spc  Tab       Ent  Bsp  AltGr                  │
│                     /SYM                /NUM                        │
└──────────────────────────────────────────────────────────────────────┘

NAV — Pfeile + Seitennavigation (linker Daumen hält)
┌──────────────────────────────────────────────────────────────────────┐
│  ·    ·    ·    ·    ·    ·   (V-) (V+)  ·    ·    ·    ·    ·   · │
│  ·   GUI  Alt  Ctrl Sft   ·  (Mut)(Ply)  ←    ↓    ↑    →    ·   · │
│  ·    ·    ·    ·    ·    ·              Home PgDn PgUp End   ·   · │
│                ░░░░  ·    ·         Ent  Bsp   ·                    │
└──────────────────────────────────────────────────────────────────────┘

SYM — Symbole (linker Daumen Space hält)
┌──────────────────────────────────────────────────────────────────────┐
│  ·    ·    ·    ·    ·    ·   (V-) (V+)  *    {    }    <    >   `  │
│  ·   GUI  Alt  Ctrl Sft   ·  (Mut)(Ply)  =    (    )    ^    :   " │
│  ·    ·    ·    ·    ·    ·              +    [    ]    ,    \   |  │
│                 ·   ░░░░  ·         Ent   _    ·                    │
└──────────────────────────────────────────────────────────────────────┘

NUM — Nummernblock links (rechter Daumen Bsp hält)
┌──────────────────────────────────────────────────────────────────────┐
│  ·    *    7    8    9    +   (V-) (V+)  ·    ·    ·    ·    ·   ·  │
│  ·    /    1    2    3    0  (Mut)(Ply)  ·   Sft  Ctrl Alt  GUI  ·  │
│  ·    ~    4    5    6    -              ·    ·    ·    ·    ·    ·  │
│                 ,    =    .          ·   ░░░░  ·                    │
└──────────────────────────────────────────────────────────────────────┘
```

`░░░░` = gehaltener Layer-Key, `(V-)` etc. = durchscheinend von BASE (KC_TRNS).

## Design-Entscheidungen

### Home Row Mods (GACS)

Reihenfolge von außen nach innen: GUI, Alt, Ctrl, Shift. Shift auf dem Zeigefinger, weil der am schnellsten ist und Shift am häufigsten gebraucht wird.

**CHORDAL_HOLD** ist der Grund, warum das überhaupt funktioniert — Modifier wird nur erkannt, wenn der zweite Tastendruck auf der *anderen* Hand liegt. Ohne das bekommt man beim schnellen Tippen ständig Fehlauslösungen (z.B. `ß` statt `ls`, weil L=Alt und S auf der selben Hand liegen → AltGr+S → ß auf EurKey).

### Timing

- `TAPPING_TERM 250` — ab wann ein gehaltener Key als Hold gilt. 250ms ist konservativ, lieber etwas träger als falsche Modifier.
- `PERMISSIVE_HOLD` — wenn du einen Tap-Hold-Key hältst und einen zweiten Key drückst *und loslässt* bevor der TAPPING_TERM abläuft, gilt der erste trotzdem als Hold. Macht Modifier+Key-Combos schneller.

### Esc auf Home-Row (nicht auf Daumen)

Esc lag vorher als `LT(1, KC_ESC)` auf dem linken inneren Daumen — Tap für Esc, Hold für NAV-Layer. Das hatte spürbare Latenz, weil QMK erst abwarten muss ob du tippst oder hältst. Jetzt ist Esc eine eigene Taste auf der Home-Row (links außen), und der Daumen ist ein reiner Layer-Key `MO(1)`. Beide reagieren sofort.

### Hyper-Key

`HYPR(KC_NO)` = Ctrl+Shift+Alt+GUI gleichzeitig. Kein Programm auf macOS belegt diesen Modifier, deshalb kann man damit kollisionsfreie Systemkürzel anlegen (z.B. in Wezterm, Raycast, Karabiner, macOS Keyboard Shortcuts).

### Delete statt doppeltem Backspace

macOS-Laptops haben keine Delete-Taste (nur Backspace). Delete oben rechts, Backspace auf dem rechten Daumen — logische Trennung.

### Dedizierte Shifts bleiben

Auch wenn Shift auf den Home Row Mods liegt (F und J), sind die dedizierten Shift-Tasten unten außen als Sicherheitsnetz sinnvoll. Besonders beim Markieren mit Shift+Pfeiltasten will man Shift dauerhaft halten, was mit HRM umständlich wäre.

### Extra-Spalten = Media

Die 4 Tasten in der Mitte (ex2-Layout) sind ergonomisch schwer zu treffen — perfekt für Dinge, die man selten aber gezielt drückt: Lautstärke, Mute, Play/Pause. Über `KC_TRNS` auf allen Layern verfügbar.

### AltGr / EurKey

`KC_RALT` auf dem rechten äußeren Daumen. Auf macOS mit EurKey-Layout ist Right Alt = AltGr, damit bekommt man ä ö ü ß € und andere europäische Zeichen.

## Dateien

| Datei | Inhalt |
|---|---|
| `keymap.c` | Komplettes Layout mit ASCII-Dokumentation |
| `config.h` | Timing-Einstellungen (TAPPING_TERM, CHORDAL_HOLD, PERMISSIVE_HOLD) |
| `rules.mk` | Build-Konfiguration (minimal) |

## Bauen und Flashen

### Via GitHub Actions (empfohlen)

1. Änderungen pushen (Workflow triggert automatisch bei Änderungen in `keyboards/crkbd/keymaps/gunters_km/`)
2. In GitHub → Actions → letzter "Build Corne Firmware" Run → Artifacts → `corne-firmware` runterladen
3. `.uf2`-Datei entpacken

### Lokal (falls QMK CLI installiert)

```bash
make crkbd/rev4_1/standard:gunters_km
```

### Flashen (RP2040)

1. Corne vom USB trennen
2. **Bootloader-Taste** (Q auf linker Hälfte, P auf rechter) **gedrückt halten**
3. USB einstecken, Taste loslassen
4. Im Finder erscheint ein USB-Laufwerk (RPI-RP2)
5. `.uf2`-Datei draufziehen
6. Corne startet automatisch neu
7. Für die andere Hälfte wiederholen

## Vorgeschichte

Vorher war die Keymap über **Vial** konfiguriert (GUI-Tool). Vial kann aber kein CHORDAL_HOLD, und ohne das waren die Home Row Mods bei schnellem Tippen unbrauchbar. Deshalb Umstieg auf Standard-QMK mit eigenem Keymap-Ordner und GitHub Actions Build-Pipeline.
