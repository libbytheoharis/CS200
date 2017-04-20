#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// CS 200
// Libby Wichman
// In Class Lab - Classes


class Room
{
	private:
		string m_title;
		int m_width;
		int m_length;

	public:
		int GetWidth()
		{
			return m_width;
		}
		int GetLength()
		{
			return m_length;
		}
		int GetArea()
		{
			return (m_width * m_length);
		}
		string GetTitle()
		{
			return m_title;
		}
		void SetTitle(string newTitle)
		{
			m_title = newTitle;
		}
		void SetDimensions(int newWidth, int newHeight)
		{
			if (newWidth > 0 && newHeight > 0)
			{
				m_width = newWidth;
				m_length = newHeight;
			}
		}
};

class Building
{
	private:
		Room* m_rooms;
		int m_roomCount;

	public:
		Building(int roomCount)
		{
			m_rooms = nullptr;
			if (roomCount > 0)
			{
				m_roomCount = roomCount;
				m_rooms = new Room[roomCount];
			}
		}
		~Building()
		{
			if (m_rooms != nullptr)
			{
				delete [] m_rooms;
			}
		}
		void SetRoomTitle(int room, string title)
		{
			if (room >= 0 && room < m_roomCount)
			{
				m_rooms[room].SetTitle(title);
			}
		}
		void SetRoomDimensions(int room, int width, int length)
		{
			if (room >= 0 && room < m_roomCount)
			{
				m_rooms[room].SetDimensions( width, length);
			}

		}
		int GetTotalArea()
		{
			int sumOfAreas = 0;

			for (int i = 0; i < m_roomCount; i++)
			{
				sumOfAreas += m_rooms[i].GetArea();
			}

			return sumOfAreas;
		}
		void PrintBuildingInformation(string filename)
		{
			ofstream output(filename);

			output << "BUILDING Dimensions: " << GetTotalArea() << " sqft" << endl << endl;

			for (int i = 0; i < m_roomCount; i++)
			{
				output << endl << "ROOM " << (i + 1) << " ("
					<< m_rooms[i].GetTitle() << "):"
					<< "\n\t * Dimensions: " << m_rooms[i].GetWidth() << " x " << m_rooms[i].GetLength()
					<< "\n\t * Area:       " << m_rooms[i].GetArea() << " sqft" << endl;
			}

			output.close();
		}
};



void RoomProgram()
{
	// This function works with the Room object

	Room room;
	room.SetDimensions( 5, 4 );

	cout << "Room area is: " << room.GetArea() << endl;

	room.SetTitle( "closet" );

	cout << "Room name is: " << room.GetTitle() << endl;
	
}

void BuildingProgram()
{
	// This function works with the Building object

	Building building( 5 );

	building.SetRoomTitle( 0, "Entryway" );
	building.SetRoomTitle( 1, "Living Room" );
	building.SetRoomTitle( 2, "Kitchen" );
	building.SetRoomTitle( 3, "Bedroom" );
	building.SetRoomTitle( 4, "Bathroom" );

	building.SetRoomDimensions( 0, 5, 10 );
	building.SetRoomDimensions( 1, 5, 10 );
	building.SetRoomDimensions( 2, 5, 10 );
	building.SetRoomDimensions( 3, 5, 10 );
	building.SetRoomDimensions( 4, 5, 10 );

	building.PrintBuildingInformation( "building.txt" );
}

int main()
{
	RoomProgram();
	BuildingProgram();

	return 0;
}