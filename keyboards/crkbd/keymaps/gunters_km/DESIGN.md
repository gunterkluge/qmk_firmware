# Design-Notizen Corne Keymap — Miryoku-Stil

## Aktuelle Belegung (7 Layer)

### BASE — QWERTY mit GACS Home Row Mods

    Hyp  Q    W    E    R    T   Vol- Vol+  Y    U    I    O    P   Del
    Esc  A/G  S/A  D/C  F/S  G   Mut  Play  H    J/S  K/C  L/A  ;/G  '
    Sft  Z    X    C    V    B              N    M    ,    .    /   Sft
                   Esc/NAV Spc/SYM1 Tab/FUN  Ent/NUM Bsp/SYM2 Del/EUR

### NAV — Navigation (linker aeusserer Daumen haelt)

    Links: Modifier              Rechts: 3 Ebenen Navigation + Loeschen + Undo

     .    .    .    .    .    .         ZAnf  Wrt<  Wrt>  ZEnd KillLn Redo
     .   GUI  Alt  Ctl  Sft   .         <-    v     ^     ->  WrtBs  Undo
     .    .    .    .    .    .         Hom   PgD   PgU   End WrtDl  Find
                   ///   .    .         Ent   Bsp   Del

### SYM1 — Symbole rechts (linker mittlerer Daumen haelt)

    Links: Modifier              Rechts: Schliessende Klammern + Operatoren

     .    .    .    .    .    .          "    +     *     ^     '    .
     .   GUI  Alt  Ctl  Sft   .         ;    )     }     ]     >    .
     .    .    .    .    .    .          '    -     :     \     |    .
                    .   ///   .          _    =     -

### SYM2 — Symbole links (rechter mittlerer Daumen haelt)

    Links: Oeffnende Klammern    Rechts: Modifier

     .    !    @    #    $    %          .    .     .     .     .    .
     .    <    [    {    (    &          .   Sft   Ctl   Alt   GUI   .
     .    ~    |    \    `    /          .    .     .     .     .    .
                    -    =    _          .   ///    .

    Klammern symmetrisch gespiegelt: gleicher Finger fuer ( ) { } [ ] < >
    = _ - auf Daumen beider SYM-Layer (immer erreichbar)

### NUM — Taschenrechner (rechter innerer Daumen haelt)

    Links: Numpad + Operatoren   Rechts: Modifier

     .    /    7    8    9    -          .    .     .     .     .    .
     .    *    4    5    6    +          .   Sft   Ctl   Alt   GUI   .
     .    ,    1    2    3    .          .    .     .     .     .    .
                   Bsp   0    =         ///   .     .

### FUN — Funktionstasten + System (linker innerer Daumen haelt)

    Links: Screenshots/Media     Rechts: F-Tasten + Helligkeit

     .  ScBer ScVol ScTlb  .    .       F12   F7    F8    F9  Bri+ MCtrl
     .   GUI  Alt  Ctl  Sft   .         F11   F4    F5    F6   .   Cmd+`
     .  Spc<  Spc> MPrv MNxt  .         F10   F1    F2    F3  Bri-  .
                    .     .  ///          .   CpWd    .

### EURKEY — Umlaute (rechter aeusserer Daumen haelt)

     .    Ae   .    Eur   .    .          .    ue    .     oe    .    .
     .    ae   ss    .    .    .          .    Ue    .     Oe    .    .
    Sft   .    .    .    .    .          .    .     .     .     .   Sft
                    .    .    .          .    .    ///

    Gleicher Finger fuer klein/gross: ae/Ae, ue/Ue, oe/Oe

### Legende

    /G = GUI  /A = Alt  /C = Ctrl  /S = Shift  (Home Row Mods, GACS)
    /// = Layer-Taste (gehalten)
    Alle Daumen sind LT (Tap + Hold): Tap sendet Taste, Hold aktiviert Layer
    (V-)(V+)(Mut)(Ply) = Extra-Spalten, auf allen Layern transparent

## Design-Entscheidungen

### Was das alte Layout nicht konnte (und jetzt geloest ist)

- ! @ # $ % & als Direkttaste: jetzt auf SYM2 obere/Home-Reihe
- F-Tasten: eigener FUN-Layer
- Umlaute ohne AltGr halten: eigener EURKEY-Layer
- Grosse Umlaute (Ae Oe Ue) ohne 3-Finger-Griff: dedizierte Tasten auf EURKEY

### Bewusste Abweichungen von Miryoku

- 7 statt 6 Layer (EURKEY zusaetzlich)
- SYM aufgeteilt in SYM1/SYM2 (symmetrische Klammern, mehr Platz)
- Mouse-Layer weggelassen (Trackpad vorhanden)
- Media-Layer weggelassen (Extra-Spalten haben Vol/Mute/Play)
- 6. Spalte fuer Comfort-Tasten (Hyper, Esc, Del, Shift)
- NAV und FUN getauscht (NAV aussen = haeufiger, besser erreichbar)

### Ergonomie-Prinzipien

- Haeufige Symbole auf Zeige-/Mittelfinger, seltene auf Pinky
- = _ - auf Daumen beider SYM-Layer: immer erreichbar, egal welcher Layer
- Klammern symmetrisch gespiegelt: gleicher Finger fuer zusammengehoerige Paare
- NAV-Layer: 3 Ebenen uebereinander (Zeile > Wort > Zeichen), gleicher Finger
- Loeschen auf NAV Pinky-Spalte: Wort/Zeile loeschen im Navigations-Flow

## Offene Ideen

- NUM-Layer-Lock (Taschenrechner-Modus feststellbar) — Risiko: vergessen
  auszuschalten, dann funktioniert nichts mehr wie erwartet. Moeglich
  ueber TG(_NUM) auf einer sicheren Position, z.B. Combo oder Doppel-Tap.
- EURKEY-Layer weiter fuellen (Guillemets, Gedankenstrich, Grad-Zeichen)
- Undo/Cut/Copy/Paste auf NAV linke Hand (Z/X/C/V als Cmd+Z/X/C/V)

## Ergonomie-Regeln (Zusammenfassung)

### Finger und Positionen

- Home Row ist die wertvollste Reihe
- Obere Reihe besser als untere (Strecken leichter als Krallen)
- Zeige- und Mittelfinger tragen die Hauptlast, Kleinfinger entlasten
- Innere Spalte (6. Spalte) nur fuer Seltenes

### Daumen

- Maximal 2-3 Daumentasten pro Hand aktiv nutzen
- Dauerhaftes Halten belastet mehr als Taps
- Bei Daumenschmerzen sofort aufhoeren — RSI am Daumen eskaliert schnell

### Layer-Design

- Ein Zweck pro Hand pro Layer (Haltehand = Modifier, andere = Inhalt)
- Haeufig gemeinsam genutzte Tasten auf denselben Layer
- Konsistente Positionen ueber Layer hinweg
