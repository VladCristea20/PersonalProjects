using Notepad.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Text;

namespace Notepad.ViewModel
{
    internal class TabControlViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        static public event PropertyChangedEventHandler StaticPropertyChanged;
        private void NotifyPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        static private void StaticNotifyPropertyChanged(string propertyName)
        {
            StaticPropertyChanged?.Invoke(null, new PropertyChangedEventArgs(propertyName));
        }


        public static ObservableCollection<TabViewModel> Tabs { get; set; } = new ObservableCollection<TabViewModel>() { new TabViewModel(new TabModel() { Name = "File 1", Text = "Write something here" }), new TabViewModel(new TabModel() { Name = "File 2", Text = "Write something here"}) };

       static private int selectedIndex;
       static public int SelectedIndex
        {
            get
            {
                return selectedIndex;
            }
            set
            {
                if(selectedIndex != value)
                {
                    selectedIndex = value;
                    StaticNotifyPropertyChanged("SelectedIndex");
                    
                }
            }
        }
    }
}
