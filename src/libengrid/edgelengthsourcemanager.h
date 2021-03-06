// 
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +                                                                      +
// + This file is part of enGrid.                                         +
// +                                                                      +
// + Copyright 2008-2013 enGits GmbH                                      +
// +                                                                      +
// + enGrid is free software: you can redistribute it and/or modify       +
// + it under the terms of the GNU General Public License as published by +
// + the Free Software Foundation, either version 3 of the License, or    +
// + (at your option) any later version.                                  +
// +                                                                      +
// + enGrid is distributed in the hope that it will be useful,            +
// + but WITHOUT ANY WARRANTY; without even the implied warranty of       +
// + MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        +
// + GNU General Public License for more details.                         +
// +                                                                      +
// + You should have received a copy of the GNU General Public License    +
// + along with enGrid. If not, see <http://www.gnu.org/licenses/>.       +
// +                                                                      +
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 

#ifndef EDGELENGTHSOURCEMANAGER_H
#define EDGELENGTHSOURCEMANAGER_H

#include <QListWidget>
#include <QDateTime>

#include "egvtkobject.h"
#include "edgelengthsource.h"

class EdgeLengthSourceManager : public EgVtkObject
{

private: // attributes

  QList<EdgeLengthSource*> m_Sources;
  QList<EdgeLengthSource*> m_Samples;
  QListWidget*             m_ListWidget;


private: // methods

  QString timeStamp() { return QDateTime::currentDateTime().toString("_yyyyMMddhhmmss"); }


public:

  EdgeLengthSourceManager();
  virtual ~EdgeLengthSourceManager();

  void   setListWidget(QListWidget *list_widget) { m_ListWidget = list_widget; }
  double minEdgeLength(vec3_t x);
  void   populateListWidget();

  void read();
  void write();
  void edit();
  void remove();
  void addSphere();
  void addCone();
  void addBox();
  void addPipe();

};

#endif // EDGELENGTHSOURCEMANAGER_H
