/*
 * Copyright (c) 2011, 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <bb/cascades/Application>

#include "GoodCitizenApp.hpp"

using ::bb::cascades::Application;

// workarond for slog2 output not showing up in IDE console
void myMessageOutput(QtMsgType type, const char* msg){
   fprintf(stderr, "%s\n", msg);
}

Q_DECL_EXPORT int main(int argc, char **argv)
{
    // This is where the server is started etc.
	Application app(argc, argv);

    qInstallMsgHandler(myMessageOutput);

     // Our app is initialized.
    GoodCitizenApp mainApp;

    // We complete the transaction started in the app constructor and start the client event loop here
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
    // not as nice of course.
    return Application::exec();
}
