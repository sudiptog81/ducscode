import 'dart:developer';

import "package:flutter/material.dart";

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Flutter Demo",
      theme: ThemeData(
        primarySwatch: Colors.green,
      ),
      home: MyHomePage(title: "NoobStuff"),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);
  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  bool _visible = false;
  String _input = "";

  final textController = TextEditingController();

  void _setText() {
    setState(() {
      _visible = true;
      _input = textController.text;
    });
  }

  @override
  void dispose() {
    textController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisSize: MainAxisSize.min,
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Container(
                padding: EdgeInsets.fromLTRB(30, 0, 30, 10),
                child: TextField(
                  textAlign: TextAlign.center,
                  controller: textController,
                  decoration: InputDecoration(
                      alignLabelWithHint: true, hintText: "Enter Something"),
                )),
            Container(
                child:
                    ButtonBar(alignment: MainAxisAlignment.center, children: [
              RaisedButton(
                child: Text(
                  "SUBMIT",
                  style: TextStyle(fontSize: 15),
                ),
                onPressed: _setText,
              ),
              RaisedButton(
                  child: Text(
                    "RESET",
                    style: TextStyle(fontSize: 15),
                  ),
                  onPressed: () {
                    _visible = !_visible;
                    textController.text = "";
                    _setText();
                  })
            ])),
            Container(
              padding: EdgeInsets.fromLTRB(30, 30, 30, 0),
              child: Column(
                children: <Widget>[
                  Visibility(
                    visible: _visible,
                    child: Text(
                      "You Entered",
                    ),
                  ),
                  Text(
                    _input,
                    style: TextStyle(fontSize: 20, color: Colors.green),
                  )
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}
