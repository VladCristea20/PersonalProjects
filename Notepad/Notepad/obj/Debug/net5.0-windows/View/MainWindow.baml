   M S B A M L   `   `   `  ����B  >Notepad, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null5clr-namespace:Notepad.ViewModelNotepad.ViewModel  5   	   !clr-namespace:NotepadNotepad  5   	       Notepad.MainWindow   5   	   W SPresentationCore, Version=5.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=5.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=5.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=5.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=5.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   6
viewmodelsclr-namespace:Notepad.ViewModel     5   	   'localclr-namespace:Notepad     5   	     � Title$  
MainWindow��5	   	   $	��450��6   $	��800��6)   .��5
      � .+�5   
   o� -   5         o�Name$
 menu��5      $��3q�6   .@�5      m� $
��File��6    � DataContext 5         Notepad.ViewModel.Commands  5      -   5        Commands��5   >   .@�5      m� $��New Tab��6    m� Command 6,   �� *NewTabCommand+m� 5      $
��Open��6    6)   �� *OpenTabCommand+m� 5      $
��Save��6    6)   �� *SaveCommand+m� 5      $��
Save as...��6    6/   �� *SaveAsCommand+m� 5      $
��Exit��6    6)   �� *ExitCommand+5      m� 5      $��Search��6    5        5      -   5        	Commands2��5   ?   .@�5      m� $
��Find��6    6)   �� *FindCommand+m� 5      $��Replace��6    6,   �� *ReplaceCommand+5      m� 5      $
��Help��6    5        5      -   5        	Commands1��5   ?   .@�5!      m� $��About��6    6*   �� *AboutCommand+5"      5#      �� 5$   
   -   5         ��Name$ 
tabControl��5$      $��0,20,0,0q�6)   ��6;   �� *Tabs+ �� SelectedIndex 6X   �� *SelectedIndex+ �� Mode$ TwoWay=� �� UpdateSourceTrigger$ PropertyChanged=� 5%      +  %Notepad.ViewModel.TabControlViewModel  5&      -   5        
TabControl��5&   1   ��5(      �� 5)      .R�5*      �� ��6   �� *Name+$ PropertyChanged=���5+      �� 5,       �� 
TargetType" ��6$   .�5-   "   �� 	 �� Property	 � ��
 �� Value

 �  ��6M    �� Triggers 5.   "   �� 5/   &    �� Binding 62   �� *Saved+ �� Value True6L   .a�50   *   �� 	 � ��

 � � �6G   51   '   53      55      56       �� ContentTemplate 58      �� 59      .R�5:      �� ��6   �� *Text+$ PropertyChanged=�6[   5;      5=      5>      5?      