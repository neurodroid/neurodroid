package org.neurodroid;

import java.util.ArrayList;
import java.util.Locale;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.Paint.Align;
import android.view.View;

import android.util.AttributeSet;

/**
 * C. Schmidt-Hieber, 2011
 * Inspired by GraphView by Arno den Hond
 * http://android.arnodenhond.com/components/graphview
 *
 */
public class GraphView extends View {

    public static boolean BAR = true;
    public static boolean LINE = false;

    private Paint paint;
    private ArrayList<Float> values;
    private String[] xlabels;
    private String[] ylabels;
    private String title;
    private String xtitle, ytitle;
    private boolean type;

    public GraphView(Context context) {
        super(context);
        initGraphView();
    }
    
    public GraphView(Context context, AttributeSet attrs) {
        super(context, attrs);
        initGraphView();
    }

    public void initGraphView() {
        values = new ArrayList<Float> ();
        title = "";
        xtitle = "Time (ms)";
        ytitle = "V (mv)";
        this.xlabels = new String[0];
        this.ylabels = new String[0];
        this.type = LINE;
        paint = new Paint();
    }
    
    public void setGraph(ArrayList<Float> values, String title) {
        setGraph(values, title, null, null, LINE);
    }

    public void setGraph(ArrayList<Float> values, String title, String[] xlabels, String[] ylabels, boolean type) {
        this.values = values;
        
        if (title == null)
            title = "";
        else
            this.title = title;
        
        if (xlabels == null)
            defaultXlabels();
        else
            this.xlabels = xlabels;

        if (ylabels == null)
            defaultYlabels();
        else
            this.ylabels = ylabels;

        this.type = type;

        this.values.remove(0); /* remove dt */
    }

    public void defaultXlabels() {
        float dt = this.values.get(0);
        float xmin = 0;
        float xmax = (this.values.size()-1) * dt;

        float xrange = xmax-xmin;
        this.xlabels = new String[] {
            "0",
            String.format(Locale.UK, "%.2f", xrange/4.0),
            String.format(Locale.UK, "%.2f", xrange/2.0),
            String.format(Locale.UK, "%.2f", xrange*3.0/4.0),
            String.format(Locale.UK, "%.2f", xrange)
        };
    }
    
    public void defaultYlabels() {
        float ymax = Integer.MIN_VALUE;
        float ymin = Integer.MAX_VALUE;
        for (int i = 0; i < values.size(); i++) {
            if (values.get(i) > ymax)
                ymax = values.get(i);
            if (values.get(i) < ymin)
                ymin = values.get(i);
        }
        
        float yrange = ymax-ymin;
        this.ylabels = new String[] {
            String.format(Locale.UK, "%.0f", yrange + ymin),
            String.format(Locale.UK, "%.0f", yrange*3.0/4.0 + ymin),
            String.format(Locale.UK, "%.0f", yrange/2.0 + ymin),
            String.format(Locale.UK, "%.0f", yrange/4.0 + ymin),
            String.format(Locale.UK, "%.0f", ymin)
        };
    }
    
    @Override protected void onDraw(Canvas canvas) {
        if (values.size()==0)
            return;
        
        float horborder = 20;
        float verborder = 30;
        float horstart = horborder * 2;
        float height = getHeight();
        float width = getWidth() - 1;
        float max = getMax();
        float min = getMin();
        float diff = max - min;
        float graphheight = height - (2 * verborder);
        float graphwidth = width - (2 * horborder);

        paint.setAntiAlias(true);
        paint.setTextAlign(Align.LEFT);
        int vers = ylabels.length - 1;
        for (int i = 0; i < ylabels.length; i++) {
            paint.setColor(Color.DKGRAY);
            float y = ((graphheight / vers) * i) + verborder;
            canvas.drawLine(horstart, y, width, y, paint);
            paint.setColor(Color.WHITE);
            paint.setTextAlign(Align.RIGHT);
            canvas.drawText(ylabels[i], horstart, y, paint);
            paint.setTextAlign(Align.LEFT);
        }
        int hors = xlabels.length - 1;
        for (int i = 0; i < xlabels.length; i++) {
            paint.setColor(Color.DKGRAY);
            float x = ((graphwidth / hors) * i) + horstart;
            canvas.drawLine(x, height - verborder, x, verborder, paint);
            paint.setTextAlign(Align.CENTER);
            if (i==xlabels.length-1)
                paint.setTextAlign(Align.RIGHT);
            if (i==0)
                paint.setTextAlign(Align.LEFT);
            paint.setColor(Color.WHITE);
            canvas.drawText(xlabels[i], x, height - 18, paint);
        }

        paint.setTextAlign(Align.CENTER);
        canvas.drawText(title, (graphwidth / 2) + horstart, verborder - 4, paint);
        canvas.drawText(xtitle, (graphwidth / 2) + horstart, height - 4, paint);

        if (max != min) {
            paint.setColor(Color.LTGRAY);
            if (type == BAR) {
                float datalength = values.size();
                float colwidth = (width - (2 * horborder)) / datalength;
                for (int i = 0; i < values.size(); i++) {
                    float val = values.get(i) - min;
                    float rat = val / diff;
                    float h = graphheight * rat;
                    canvas.drawRect((i * colwidth) + horstart, (verborder - h) + graphheight, ((i * colwidth) + horstart) + (colwidth - 1), height - (verborder - 1), paint);
                }
            } else {
                float datalength = values.size();
                float colwidth = (width - (2 * horborder)) / datalength;
                float halfcol = colwidth / 2;
                float lasth = 0;
                paint.setStrokeWidth(2.0f);
                for (int i = 0; i < values.size(); i++) {
                    float val = values.get(i) - min;
                    float rat = val / diff;
                    float h = graphheight * rat;
                    if (i > 0)
                        canvas.drawLine(((i - 1) * colwidth) + (horstart + 1) + halfcol, (verborder - lasth) + graphheight, (i * colwidth) + (horstart + 1) + halfcol, (verborder - h) + graphheight, paint);
                    lasth = h;
                }
            }
        }

        /* Rotate text for y title */
        Rect rect = new Rect();
        paint.getTextBounds(ytitle, 0, ytitle.length(), rect);
        float yty = graphheight / 2 - vers;
        float ytx = 12;
        canvas.rotate(-90, ytx + rect.exactCenterX(), yty + rect.exactCenterX());
        canvas.drawText(ytitle, ytx, yty, paint);
    }

    private float getMax() {
        float largest = Integer.MIN_VALUE;
        for (int i = 0; i < values.size(); i++)
            if (values.get(i) > largest)
                largest = values.get(i);
        return largest;
    }

    private float getMin() {
        float smallest = Integer.MAX_VALUE;
        for (int i = 0; i < values.size(); i++)
            if (values.get(i) < smallest)
                smallest = values.get(i);
        return smallest;
    }

}
