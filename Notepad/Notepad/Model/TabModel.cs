using System;
using System.Collections.Generic;
using System.Text;

namespace Notepad.Model
{
    class TabModel
    {
        public string Name { get; set; } = "";
        public string Text{ get; set ;}= "";

        public bool Saved { get; set; } = false;

    }
}
