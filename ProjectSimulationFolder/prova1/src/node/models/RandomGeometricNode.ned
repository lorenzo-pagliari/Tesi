//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package prova1.node.models;

import prova1.node.INode;

simple RandomGeometricNode like INode
{
    parameters:
        int areaLength = default(10);
        int areaWidth = default(10);
        double xPos = uniform(0, areaLength);
        double yPos = uniform(0, areaLength);

        @display("i=misc/node_vs;is=vs");
        
//      display radius non è utile perchè anche lui
//		si basa sui pixel
//      	@display("r=15");
    gates:
        inout g[];
}

