/*
 * Publication: Semi-Procedural Textures Using Point Process Texture Basis Functions
 *              Computer Graphics Forum (EGSR 2020 special issue)
 * Authors: P. Guehl , R. AllEgre , J.-M. Dischler, B. Benes , and E. Galin
 *
 * Code author: Pascal Guehl
 */

/** 
 * @version 1.0
 */

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/

// STL
#include <iostream>
#include <string>

// System
#include <cstdlib>
#include <ctime>

// Project
#include "PtApplication.h"
#include "PtGraphicsPPTBF.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

/******************************************************************************
 ************************* DEFINE AND CONSTANT SECTION ************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

/******************************************************************************
 * Main entry program
 *
 * @param pArgc Number of arguments
 * @param pArgv List of arguments
 *
 * @return flag telling whether or not it succeeds
 ******************************************************************************/
int main( int pArgc, char** pArgv )
{
	// LOG info
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "- PPTBF Structures BDD Generator on GPU: Command Line Tool --" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;

	// Check command line arguments
	const int nbArguments = 4;
	if ( pArgc < ( 1 + nbArguments ) )
	{
		std::cout << "ERROR: program requires 4 parameters..." << std::endl;
		std::cout << "\tprogram width height BDDImageDirectory BDDserieID" << std::endl;

		// Exit
		return -1;
	}

	// Retrieve program directory
	int indexParameter = 0;
	std::string workingDirectory = "";
	workingDirectory = pArgv[ indexParameter++ ];

	// User customizable parameters : retrieve command line parameters
	const int BDDImageWidth = std::stoi( pArgv[ indexParameter++ ] ); // default: 4
	const int BDDImageHeight = std::stoi( pArgv[ indexParameter++ ] ); // default: 4
	const char* BDDImageDirectory = pArgv[ indexParameter++ ]; // default: "../imagestp/many_lichens_on_stone_6040019"
	const int BDDserieID = std::stoi( pArgv[ indexParameter++ ] );
	
	PtGUI::PtApplication& application = PtGUI::PtApplication::get();
	
	// Initialization
	application.initialize( workingDirectory.c_str() );

	// Set user parameters
	application.setBDDImageWidth( BDDImageWidth );
	application.setBDDImageHeight( BDDImageHeight );
	application.setBDDImageDirectory( BDDImageDirectory );
	application.setBDDSerieID( BDDserieID );
		
	PtGUI::PtApplication::get().execute();

	// LOG info
	std::cout << "---------------------" << std::endl;
	std::cout << "- This is the end! --" << std::endl;
	std::cout << "---------------------" << std::endl;
	
	// Finalization
	application.finalize();
	
	return 0;
}
