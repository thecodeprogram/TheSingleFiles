/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 07.04.2020
*/

import React, { Component } from 'react';
import {
  Text,
  View,
  Dimensions,
  TouchableHighlight,
  StyleSheet, 
  Animated,
} from 'react-native';

const pageWidth  = Dimensions.get('window').width;

export default class ToastExample extends Component<{}> {

  constructor(props) {
    super(props);
    this.state = {

      modalShown: false,
      toastColor: 'green',
      message: 'Success!',

    };

    this.animatedValue = new Animated.Value(0)

  }

   callToast(message, type) {
    if(this.state.modalShown) return
    this.setToastType(message, type)
    this.setState({ modalShown: true })
    Animated.timing(
      this.animatedValue,
      {
        toValue: 1,
        duration: 350
      }).start(this.closeToast())
  }
  
  closeToast() {
    setTimeout(() => {
      this.setState({ modalShown: false })
      Animated.timing(
      this.animatedValue,
      { 
        toValue: 0,
        duration: 350
      }).start()
    }, 2000)
  }

  setToastType(message='Success!', type='success') {
    let color
    if (type == 'error') color = 'red'
    if (type == 'warning') color = 'yellow'
    if (type == 'success') color = 'green'
    this.setState({ toastColor: color, message: message })
  }


  componentDidMount() {

  }

  render() {

    let animation = this.animatedValue.interpolate({
       inputRange: [0, .3, 1],
       outputRange: [-70, -10, 0]
     })

    return (

      <View style={styles.container}>

            <Animated.View  style={{ transform: [{ translateY: animation }], height: 70, backgroundColor: this.state.toastColor, position: 'absolute',left:0, top:0, right:0, justifyContent:  'center', zIndex:1000 }}>
              <Text style={{ marginLeft: 10,  color: 'white',  fontSize:16, fontWeight: 'bold' }}>
                { this.state.message }
              </Text>
            </Animated.View>

         <View style={{ width: pageWidth,
                        backgroundColor: '#f8f8ff', 
                        borderRadius:5, 
                        borderWidth: 1, 
                        borderColor: '#000',
                        marginTop: 1, }} >
              <TouchableHighlight 
                style={{
                    backgroundColor: 'red',
                  }} 
                onPress={() => {
                  this.callToast("Error Message", 'error');
                }}  >
                <Text style={styles.modalContentStyle}>
                  {"Show Error Message"}
                </Text>
            </TouchableHighlight> 
            <TouchableHighlight 
                style={{
                    backgroundColor: 'yellow',
                  }} 
                onPress={() => {
                  this.callToast("Warning Message", 'warning');
                }}  >
                <Text style={styles.modalContentStyle}>
                  {"Show Warning Message"}
                </Text>
            </TouchableHighlight> 
            <TouchableHighlight 
                style={{
                    backgroundColor: 'green',
                  }} 
                onPress={() => {
                  this.callToast("Success Message", 'success');
                }}  >
                <Text style={styles.modalContentStyle}>
                  {"Show Success Message"}
                </Text>
            </TouchableHighlight> 
          </View>
        
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  modalContentStyle:{
    fontSize: 15,
    fontWeight: 'bold',
  },
 
});
