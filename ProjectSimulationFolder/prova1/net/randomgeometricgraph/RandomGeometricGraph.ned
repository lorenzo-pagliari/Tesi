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

package prova1.net.randomgeometricgraph;

import prova1.node.models.RandomGeometricNode;

network RandomGeometricGraph {
    
    parameters:
        int radius;
        int netSize;

//        @display("bgg=10");
        
    submodules:
        rgnv[netSize]: RandomGeometricNode;
        
    connections:
        
		for i = 0..netSize-2, for j=i+1..netSize-1 {
		     rgnv[i].g++ <--> rgnv[j].g++ if (radius > sqrt((rgnv[i].xPos-rgnv[j].xPos)*(rgnv[i].xPos-rgnv[j].xPos) + 
            												(rgnv[i].yPos-rgnv[j].yPos)*(rgnv[i].yPos-rgnv[j].yPos)));
        }
}