/* 
 * tkWin3d.c --
 *
 *	This file contains the platform specific routines for
 *	drawing 3d borders in the Windows 95 style.
 *
 * Copyright (c) 1996 by Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * SCCS: @(#) tkWin3d.c 1.6 97/08/12 14:28:54
 */

#include <tk3d.h>
#include <tkWinInt.h>

/*
 * This structure is used to keep track of the extra colors used by
 * Windows 3d borders.
 */

typedef struct {
    TkBorder info;
    XColor *light2ColorPtr; /* System3dLight */
    XColor *dark2ColorPtr;  /* System3dDarkShadow */
} WinBorder;


/*
 *----------------------------------------------------------------------
 *
 * TkpGetBorder --
 *
 *	This function allocates a new TkBorder structure.
 *
 * Results:
 *	Returns a newly allocated TkBorder.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

TkBorder *
TkpGetBorder()
{
    WinBorder *borderPtr = (WinBorder *) ckalloc(sizeof(WinBorder));
    borderPtr->light2ColorPtr = NULL;
    borderPtr->dark2ColorPtr = NULL;
    return (TkBorder *) borderPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * TkpFreeBorder --
 *
 *	This function frees any colors allocated by the platform
 *	specific part of this module.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	May deallocate some colors.
 *
 *----------------------------------------------------------------------
 */

void
TkpFreeBorder(borderPtr)
    TkBorder *borderPtr;
{
    WinBorder *winBorderPtr = (WinBorder *) borderPtr;
    if (winBorderPtr->light2ColorPtr) {
	Tk_FreeColor(winBorderPtr->light2ColorPtr);
    }
    if (winBorderPtr->dark2ColorPtr) {
	Tk_FreeColor(winBorderPtr->dark2ColorPtr);
    }
}

/*
 *--------------------------------------------------------------
 *
 * Tk_3DVerticalBevel --
 *
 *	This procedure draws a vertical bevel along one side of
 *	an object.  The bevel is always rectangular in shape:
 *			|||
 *			|||
 *			|||
 *			|||
 *			|||
 *			|||
 *	An appropriate shadow color is chosen for the bevel based
 *	on the leftBevel and relief arguments.  Normally this
 *	procedure is called first, then Tk_3DHorizontalBevel is
 *	called next to draw neat corners.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Graphics are drawn in drawable.
 *
 *--------------------------------------------------------------
 */

void
Tk_3DVerticalBevel(tkwin, drawable, border, x, y, width, height,
	leftBevel, relief)
    Tk_Window tkwin;		/* Window for which border was allocated. */
    Drawable drawable;		/* X window or pixmap in which to draw. */
    Tk_3DBorder border;		/* Token for border to draw. */
    int x, y, width, height;	/* Area of vertical bevel. */
    int leftBevel;		/* Non-zero means this bevel forms the
				 * left side of the object;  0 means it
				 * forms the right side. */
    int relief;			/* Kind of bevel to draw.  For example,
				 * TK_RELIEF_RAISED means interior of
				 * object should appear higher than
				 * exterior. */
{
    TkBorder *borderPtr = (TkBorder *) border;
    int left, right;
#ifdef FILLRECTGC
    GC leftgc=None; 
    GC rightgc=None;
#endif
    Display *display = Tk_Display(tkwin);
    TkWinDCState state;
    HDC dc = TkWinGetDrawableDC(display, drawable, &state);
    int half;

    if ((borderPtr->lightGC == None) && (relief != TK_RELIEF_FLAT)) {
	TkpGetShadows(borderPtr, tkwin);
    }

    switch (relief) {
	case TK_RELIEF_RAISED:
	    left = (leftBevel)
		? borderPtr->lightGC->foreground
		: borderPtr->darkGC->foreground;
#ifdef FILLRECTGC
	    leftgc = (leftBevel)
		? borderPtr->lightGC
		: borderPtr->darkGC;
#endif
	    right = (leftBevel)
		? ((WinBorder *)borderPtr)->light2ColorPtr->pixel
		: ((WinBorder *)borderPtr)->dark2ColorPtr->pixel;
	    break;
	case TK_RELIEF_SUNKEN:
	    left = (leftBevel)
		? ((WinBorder *)borderPtr)->dark2ColorPtr->pixel
		: ((WinBorder *)borderPtr)->light2ColorPtr->pixel;
	    right = (leftBevel)
		? borderPtr->darkGC->foreground
		: borderPtr->lightGC->foreground;
#ifdef FILLRECTGC
	    rightgc = (leftBevel)
		? borderPtr->darkGC
		: borderPtr->lightGC;
#endif
	    break;
	case TK_RELIEF_RIDGE:
	    left = borderPtr->lightGC->foreground;
	    right = borderPtr->darkGC->foreground;
#ifdef FILLRECTGC
	    leftgc = borderPtr->lightGC;
	    rightgc = borderPtr->darkGC;
#endif
	    break;
	case TK_RELIEF_GROOVE:
	    left = borderPtr->darkGC->foreground;
	    right = borderPtr->lightGC->foreground;
#ifdef FILLRECTGC
	    leftgc = borderPtr->darkGC;
	    rightgc = borderPtr->lightGC;
#endif
	    break;
	case TK_RELIEF_FLAT:
#ifdef FILLRECTGC
	    left = right = borderPtr->bgGC->foreground;
	    leftgc = rightgc = borderPtr->bgGC;
#endif
	    break;
	case TK_RELIEF_SOLID:
	    left = right = RGB(0,0,0);
	    break;
    }
    half = width/2;
    if (leftBevel && (width & 1)) {
	half++;
    }
#ifdef FILLRECTGC
    (leftgc!=None)?
      TkWinFillRectGC(dc, x, y, half, height, left,leftgc):
#endif
      TkWinFillRect(dc, x, y, half, height, left);
#ifdef FILLRECTGC
    (rightgc!=None)?
      TkWinFillRectGC(dc, x+half, y, width-half, height, right,rightgc):
#endif
      TkWinFillRect(dc, x+half, y, width-half, height, right);
    TkWinReleaseDrawableDC(drawable, dc, &state);
}

/*
 *--------------------------------------------------------------
 *
 * Tk_3DHorizontalBevel --
 *
 *	This procedure draws a horizontal bevel along one side of
 *	an object.  The bevel has mitered corners (depending on
 *	leftIn and rightIn arguments).
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	None.
 *
 *--------------------------------------------------------------
 */

void
Tk_3DHorizontalBevel(tkwin, drawable, border, x, y, width, height,
	leftIn, rightIn, topBevel, relief)
    Tk_Window tkwin;		/* Window for which border was allocated. */
    Drawable drawable;		/* X window or pixmap in which to draw. */
    Tk_3DBorder border;		/* Token for border to draw. */
    int x, y, width, height;	/* Bounding box of area of bevel.  Height
				 * gives width of border. */
    int leftIn, rightIn;	/* Describes whether the left and right
				 * edges of the bevel angle in or out as
				 * they go down.  For example, if "leftIn"
				 * is true, the left side of the bevel
				 * looks like this:
				 *	___________
				 *	 __________
				 *	  _________
				 *	   ________
				 */
    int topBevel;		/* Non-zero means this bevel forms the
				 * top side of the object;  0 means it
				 * forms the bottom side. */
    int relief;			/* Kind of bevel to draw.  For example,
				 * TK_RELIEF_RAISED means interior of
				 * object should appear higher than
				 * exterior. */
{
    TkBorder *borderPtr = (TkBorder *) border;
    Display *display = Tk_Display(tkwin);
    int bottom, halfway, x1, x2, x1Delta, x2Delta;
    TkWinDCState state;
    HDC dc = TkWinGetDrawableDC(display, drawable, &state);
    int topColor, bottomColor;

    if ((borderPtr->lightGC == None) && (relief != TK_RELIEF_FLAT)) {
	TkpGetShadows(borderPtr, tkwin);
    }

    /*
     * Compute a GC for the top half of the bevel and a GC for the
     * bottom half (they're the same in many cases).
     */

    switch (relief) {
	case TK_RELIEF_RAISED:
	    topColor = (topBevel)
		? borderPtr->lightGC->foreground
		: borderPtr->darkGC->foreground;
	    bottomColor = (topBevel)
		? ((WinBorder *)borderPtr)->light2ColorPtr->pixel
		: ((WinBorder *)borderPtr)->dark2ColorPtr->pixel;
	    break;
	case TK_RELIEF_SUNKEN:
	    topColor = (topBevel)
		? ((WinBorder *)borderPtr)->dark2ColorPtr->pixel
		: ((WinBorder *)borderPtr)->light2ColorPtr->pixel;
	    bottomColor = (topBevel)
		? borderPtr->darkGC->foreground
		: borderPtr->lightGC->foreground;
	    break;
	case TK_RELIEF_RIDGE:
	    topColor = borderPtr->lightGC->foreground;
	    bottomColor = borderPtr->darkGC->foreground;
	    break;
	case TK_RELIEF_GROOVE:
	    topColor = borderPtr->darkGC->foreground;
	    bottomColor = borderPtr->lightGC->foreground;
	    break;
	case TK_RELIEF_FLAT:
	    topColor = bottomColor = borderPtr->bgGC->foreground;
	    break;
	case TK_RELIEF_SOLID:
	    topColor = bottomColor = RGB(0,0,0);
    }

    /*
     * Compute various other geometry-related stuff.
     */

    if (leftIn) {
	x1 = x+1;
    } else {
	x1 = x+height-1;
    }
    x2 = x+width;
    if (rightIn) {
	x2--;
    } else {
	x2 -= height;
    }
    x1Delta = (leftIn) ? 1 : -1;
    x2Delta = (rightIn) ? -1 : 1;
    halfway = y + height/2;
    if (topBevel && (height & 1)) {
	halfway++;
    }
    bottom = y + height;

    /*
     * Draw one line for each y-coordinate covered by the bevel.
     */

    for ( ; y < bottom; y++) {
	/*
	 * In some weird cases (such as large border widths for skinny
	 * rectangles) x1 can be >= x2.  Don't draw the lines
	 * in these cases.
	 */

	if (x1 < x2) {
	    TkWinFillRect(dc, x1, y, x2-x1, 1,
		(y < halfway) ? topColor : bottomColor);
	}
	x1 += x1Delta;
	x2 += x2Delta;
    }
    TkWinReleaseDrawableDC(drawable, dc, &state);
}

/*
 *----------------------------------------------------------------------
 *
 * TkpGetShadows --
 *
 *	This procedure computes the shadow colors for a 3-D border
 *	and fills in the corresponding fields of the Border structure.
 *	It's called lazily, so that the colors aren't allocated until
 *	something is actually drawn with them.  That way, if a border
 *	is only used for flat backgrounds the shadow colors will
 *	never be allocated.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	The lightGC and darkGC fields in borderPtr get filled in,
 *	if they weren't already.
 *
 *----------------------------------------------------------------------
 */

void
TkpGetShadows(borderPtr, tkwin)
    TkBorder *borderPtr;	/* Information about border. */
    Tk_Window tkwin;		/* Window where border will be used for
				 * drawing. */
{
    XColor lightColor, darkColor;
    int tmp1, tmp2;
    XGCValues gcValues;

    if (borderPtr->lightGC != None) {
	return;
    }

    /*
     * Handle the special case of the default system colors.
     */

    if ((TkWinIndexOfColor(borderPtr->bgColorPtr) == COLOR_3DFACE)
	|| (TkWinIndexOfColor(borderPtr->bgColorPtr) == COLOR_WINDOW)) {
	borderPtr->darkColorPtr = Tk_GetColor(NULL, tkwin,
	    Tk_GetUid("SystemButtonShadow"));
	gcValues.foreground = borderPtr->darkColorPtr->pixel;
	borderPtr->darkGC = Tk_GetGC(tkwin, GCForeground, &gcValues);
	borderPtr->lightColorPtr = Tk_GetColor(NULL, tkwin,
	    Tk_GetUid("SystemButtonHighlight"));
	gcValues.foreground = borderPtr->lightColorPtr->pixel;
	borderPtr->lightGC = Tk_GetGC(tkwin, GCForeground, &gcValues);
	((WinBorder*)borderPtr)->dark2ColorPtr = Tk_GetColor(NULL, tkwin,
		Tk_GetUid("System3dDarkShadow"));
	((WinBorder*)borderPtr)->light2ColorPtr = Tk_GetColor(NULL, tkwin,
		Tk_GetUid("System3dLight"));
	return;
    } else {
	darkColor.red = 0;
	darkColor.green = 0;
	darkColor.blue = 0;
	((WinBorder*)borderPtr)->dark2ColorPtr = Tk_GetColorByValue(tkwin,
	    &darkColor);
	lightColor = *(borderPtr->bgColorPtr);
	((WinBorder*)borderPtr)->light2ColorPtr = Tk_GetColorByValue(tkwin, 
	    &lightColor);
    }
    
    /*
     * First, handle the case of a color display with lots of colors.
     * The shadow colors get computed using whichever formula results
     * in the greatest change in color:
     * 1. Lighter shadow is half-way to white, darker shadow is half
     *    way to dark.
     * 2. Lighter shadow is 40% brighter than background, darker shadow
     *    is 40% darker than background.
     */

    if (Tk_Depth(tkwin) >= 6) {
	/*
	 * This is a color display with lots of colors.  For the dark
	 * shadow, cut 40% from each of the background color components.
	 * For the light shadow, boost each component by 40% or half-way
	 * to white, whichever is greater (the first approach works
	 * better for unsaturated colors, the second for saturated ones).
	 */

	darkColor.red = (60 * (int) borderPtr->bgColorPtr->red)/100;
	darkColor.green = (60 * (int) borderPtr->bgColorPtr->green)/100;
	darkColor.blue = (60 * (int) borderPtr->bgColorPtr->blue)/100;
	borderPtr->darkColorPtr = Tk_GetColorByValue(tkwin, &darkColor);
	gcValues.foreground = borderPtr->darkColorPtr->pixel;
	borderPtr->darkGC = Tk_GetGC(tkwin, GCForeground, &gcValues);

	/*
	 * Compute the colors using integers, not using lightColor.red
	 * etc.: these are shorts and may have problems with integer
	 * overflow.
	 */

	tmp1 = (14 * (int) borderPtr->bgColorPtr->red)/10;
	if (tmp1 > MAX_INTENSITY) {
	    tmp1 = MAX_INTENSITY;
	}
	tmp2 = (MAX_INTENSITY + (int) borderPtr->bgColorPtr->red)/2;
	lightColor.red = (tmp1 > tmp2) ? tmp1 : tmp2;
	tmp1 = (14 * (int) borderPtr->bgColorPtr->green)/10;
	if (tmp1 > MAX_INTENSITY) {
	    tmp1 = MAX_INTENSITY;
	}
	tmp2 = (MAX_INTENSITY + (int) borderPtr->bgColorPtr->green)/2;
	lightColor.green = (tmp1 > tmp2) ? tmp1 : tmp2;
	tmp1 = (14 * (int) borderPtr->bgColorPtr->blue)/10;
	if (tmp1 > MAX_INTENSITY) {
	    tmp1 = MAX_INTENSITY;
	}
	tmp2 = (MAX_INTENSITY + (int) borderPtr->bgColorPtr->blue)/2;
	lightColor.blue = (tmp1 > tmp2) ? tmp1 : tmp2;
	borderPtr->lightColorPtr = Tk_GetColorByValue(tkwin, &lightColor);
	gcValues.foreground = borderPtr->lightColorPtr->pixel;
	borderPtr->lightGC = Tk_GetGC(tkwin, GCForeground, &gcValues);
	return;
    }

    if (borderPtr->shadow == None) {
	borderPtr->shadow = Tk_GetBitmap((Tcl_Interp *) NULL, tkwin,
		Tk_GetUid("gray50"));
	if (borderPtr->shadow == None) {
	    panic("TkpGetShadows couldn't allocate bitmap for border");
	}
    }
    if (borderPtr->visual->map_entries > 2) {
	/*
	 * This isn't a monochrome display, but the colormap either
	 * ran out of entries or didn't have very many to begin with.
	 * Generate the light shadows with a white stipple and the
	 * dark shadows with a black stipple.
	 */

	gcValues.foreground = borderPtr->bgColorPtr->pixel;
	gcValues.background = BlackPixelOfScreen(borderPtr->screen);
	gcValues.stipple = borderPtr->shadow;
	gcValues.fill_style = FillOpaqueStippled;
	borderPtr->darkGC = Tk_GetGC(tkwin,
		GCForeground|GCBackground|GCStipple|GCFillStyle, &gcValues);
	gcValues.foreground = WhitePixelOfScreen(borderPtr->screen);
	gcValues.background = borderPtr->bgColorPtr->pixel;
	borderPtr->lightGC = Tk_GetGC(tkwin,
		GCForeground|GCBackground|GCStipple|GCFillStyle, &gcValues);
	return;
    }

    /*
     * This is just a measly monochrome display, hardly even worth its
     * existence on this earth.  Make one shadow a 50% stipple and the
     * other the opposite of the background.
     */

    gcValues.foreground = WhitePixelOfScreen(borderPtr->screen);
    gcValues.background = BlackPixelOfScreen(borderPtr->screen);
    gcValues.stipple = borderPtr->shadow;
    gcValues.fill_style = FillOpaqueStippled;
    borderPtr->lightGC = Tk_GetGC(tkwin,
	    GCForeground|GCBackground|GCStipple|GCFillStyle, &gcValues);
    if (borderPtr->bgColorPtr->pixel
	    == WhitePixelOfScreen(borderPtr->screen)) {
	gcValues.foreground = BlackPixelOfScreen(borderPtr->screen);
	borderPtr->darkGC = Tk_GetGC(tkwin, GCForeground, &gcValues);
    } else {
	borderPtr->darkGC = borderPtr->lightGC;
	borderPtr->lightGC = Tk_GetGC(tkwin, GCForeground, &gcValues);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * TkWinGetBorderPixels --
 *
 *	This routine returns the 5 COLORREFs used to draw a given
 *	3d border.  
 *
 * Results:
 *	Returns the colors in the specified array.
 *
 * Side effects:
 *	May cause the remaining colors to be allocated.
 *
 *----------------------------------------------------------------------
 */

COLORREF
TkWinGetBorderPixels(tkwin, border, which)
    Tk_Window tkwin;
    Tk_3DBorder border;
    int which;			/* One of TK_3D_FLAT_GC, TK_3D_LIGHT_GC,
				 * TK_3D_DARK_GC, TK_3D_LIGHT2, TK_3D_DARK2 */
{
    WinBorder *borderPtr = (WinBorder *) border;
    
    if (borderPtr->info.lightGC == None) {
	TkpGetShadows(&borderPtr->info, tkwin);
    }
    switch (which) {
	case TK_3D_FLAT_GC:
	    return borderPtr->info.bgColorPtr->pixel;
	case TK_3D_LIGHT_GC:
	    if (borderPtr->info.lightColorPtr == NULL) {
		return WhitePixelOfScreen(borderPtr->info.screen);
	    }
	    return borderPtr->info.lightColorPtr->pixel;
	case TK_3D_DARK_GC:
	    if (borderPtr->info.darkColorPtr == NULL) {
		return BlackPixelOfScreen(borderPtr->info.screen);
	    }
	    return borderPtr->info.darkColorPtr->pixel;
	case TK_3D_LIGHT2:
	    return borderPtr->light2ColorPtr->pixel;
	case TK_3D_DARK2:
	    return borderPtr->dark2ColorPtr->pixel;
    }
    return 0;
}
