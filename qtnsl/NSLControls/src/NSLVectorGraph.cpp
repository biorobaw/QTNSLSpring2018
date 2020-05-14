#include "../incl/NSLVectorGraph.h"
#include <iostream>

NSLVectorGraph::NSLVectorGraph(QWidget *parent, int x, int y, int vsize, int cx, int cy, float ixmax, float ixmin,
		float iymax, float iymin, float xs, float ys) : drawRef(parent), X(x), Y(y), vectorSize(vsize), cellX(cx), cellY(cy), Xscale(xs),
		Yscale(ys), xmax(ixmax), xmin(ixmin), ymax(iymax), ymin(iymin)
{
	Canvas.resize(cellX*vsize + 10, cellY*(vsize/10) + 10);

	graph = new QCustomPlot*[vsize];
	xdata = new QVector<double>[vsize];
	ydata = new QVector<double>[vsize];

	for (int i = 0; i < vsize; i++)
	{
		graph[i] = new QCustomPlot(&Canvas);
		graph[i]->resize(cellX, cellY);
		graph[i]->move(X + cellX*(i%10) + 10, Y + cellY*(i/10));
	}

	charcount = (vectorSize/10) > 0 ? 24*(vectorSize/10) : 24;

	labels = new char[charcount + 1];
	for (int i = 0; i < charcount; i++)
		labels[i] = 0;
}

NSLVectorGraph::~NSLVectorGraph()
{
	for (int i = 0; i < vectorSize; i++)
		delete graph[i];

	delete[] graph;
	delete[] xdata;
	delete[] ydata;
	delete[] labels;
}

void NSLVectorGraph::AddPoint(int element, float y)
{
	if (element >= vectorSize)
		return;

	xdata[element].append(xdata[element].back() + 1); //incrementation of steps
	ydata[element].append(y);
	graph[element]->graph(0)->setData(xdata[element], ydata[element]);
}

void NSLVectorGraph::AddLabel(const char *label, int level)
{
strcpy(&labels[level*24], label);
}

void NSLVectorGraph::Draw()
{
	char buf[8];
	for (int i = 0; i < vectorSize; i++)
	{
		xdata[i].resize(100);
		ydata[i].resize(100);

		graph[i]->addGraph();
		graph[i]->yAxis->setRange(ymin, ymax);
		graph[i]->xAxis->setRange(xmin, xmax);

		sprintf(buf, "%d", 8); //itoa(i%10, buf, 10);
		std::string xlabel(&labels[24*(i/10)]);

		if (xlabel.length() != 0)
		{
		xlabel += buf;
		xlabel += " Step";
		graph[i]->xAxis->setLabel(xlabel.c_str());
		}
	}
}

void NSLVectorGraph::Refresh(int element)
{
	if (element >= vectorSize)
		return;

	graph[element]->replot();
}

void NSLVectorGraph::Refresh()
{
	for (int i = 0; i < vectorSize; i++)
		graph[i]->replot();
}

void NSLVectorGraph::show()
{
	Canvas.show();
}

void NSLVectorGraph::ConfigureCell(int cx, int cy)
{
cellX = cx;
cellY = cy;
}
