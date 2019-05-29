#!/bin/sh

dwm_path="/home/myc3lium/repos/personal/dwm-revised/dwm"
export PATH="${PATH}:${HOME}/local/bin/:${HOME}/.bin"

# Remap CapsLock to Esc.
xmodmap -e "keysym Caps_Lock = Escape"
xmodmap -e "clear lock"

# Set wallpaper and colors
wal -Rn
"$HOME"/.fehbg

# Battery notifications
battery-notify &

# Start compton and redshift
compton-start -s &
redshift -O 4450k &

# Start cmus and ranger in the videos directory.
(urxvt -name "music-cmus"  -uc -e cmus) 2>/dev/null &
(urxvt -name "music-mpv"   -uc -e ranger "$HOME"/Videos/yt/greentexts) 2>/dev/null &
cmus-notify &

# Start basic terminal.
(urxvt -uc -name "workspace4-terminal" -e bash) 2>/dev/null &
# Start calendar and process monitor.
(urxvt -name "calendar" -uc -e calcurse) 2>/dev/null &
(urxvt -name "monitor"  -uc -e htop) 2>/dev/null &

# Start bar script.
(bar) &

# Start dwm.
dwm_msg_file=$(mktemp)
export dwm_msg_file
while true; do
	. "$HOME"/.cache/wal/colors.sh
	echo > "$dwm_msg_file"

    $dwm_path  -nb $background -nf $foreground -sf $background -sb $color2
	[ "$(cat "$dwm_msg_file")" = "restart" ] && continue 
	break
done

killall cmus
killall calcurse
killall htop
killall ranger
killall urxvt
killall bar
killall mpv
