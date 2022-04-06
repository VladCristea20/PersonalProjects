using Notepad.Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace Notepad.ViewModel
{
    class TabViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private void NotifyPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        private readonly TabModel tabModel;

        public TabViewModel(TabModel tabModel)
        {
            this.tabModel = tabModel;
        }

        public string Name
        {
            get => tabModel.Name;
            set
            {
                if(value != tabModel.Name)
                {
                    tabModel.Name = value;
                    NotifyPropertyChanged("Name");
                }
            }
        }

        public string Text
        {
            get => tabModel.Text;
            set
            {
                if (value != tabModel.Text)
                {
                    Saved = false;
                    tabModel.Text = value;
                    NotifyPropertyChanged("Text");
                }
            }
        }

        public bool Saved 
        { 
            get => tabModel.Saved;
            set
            {
                if(value != tabModel.Saved)
                {
                    tabModel.Saved = value;
                    NotifyPropertyChanged("Saved");
                }
            }
        }
    }
}
