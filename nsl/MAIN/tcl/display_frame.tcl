# NSL2.8: display_frame.tcl
# AW - 12/95

proc grid { win w h } {
   canvas $win.canvas -width ${w}c -height ${h}c
   pack $win.canvas
   set x1 [expr $w - 1]
   set x11 [expr $x1 - 1]
   set y1 [expr $h - 1]
   set y11 [expr $y1 - 1]
   $win.canvas create line 1c 1c 1c ${y1}c ${x1}c ${y1}c ${x1}c 1c 1c 1c
   for { set i 0 } {$i < $x11 } { incr i } {
	set x [expr $i + 1]
	$win.canvas create line ${x}c ${y1}c ${x}c $y1.4c
	$win.canvas create line $x.25c ${y1}c $x.25c $y1.2c
	$win.canvas create line $x.5c ${y1}c $x.5c $y1.3c
	$win.canvas create line $x.75c ${y1}c $x.75c $y1.2c
	$win.canvas create text ${x}c $y1.4c -text $i -anchor n
   }
   for { set i 0 } {$i < $y11 } { incr i } {
	set y [expr $y11 - $i]
	$win.canvas create line 1c [expr $y+1]c 0.6c [expr $y+1]c
	$win.canvas create line 1c $y.75c 0.8c $y.75c
	$win.canvas create line 1c $y.5c 0.7c $y.5c
	$win.canvas create line 1c $y.25c 0.8c $y.25c
	$win.canvas create text 0.6c [expr $y+1]c -text $i -anchor e
   }
}

toplevel .frame1
frame .frame1.win1 -relief groove -borderwidth 4 
frame .frame1.win2 -relief groove -borderwidth 4
pack .frame1.win1 .frame1.win2 -side left

grid .frame1.win1 15 10
grid .frame1.win2 15 10

