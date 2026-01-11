pipeline {
    agent any
    
    parameters {
        choice(
            name: 'BUILD_TYPE',
            choices: ['develop', 'prod'],
            description: 'Build type'
        )
        string(
            name: 'SERVER_PORT',
            defaultValue: '8080',
            description: 'Server port'
        )
        string(
            name: 'LOG_LEVEL',
            defaultValue: 'INFO',
            description: 'Logging level'
        )
        booleanParam(
            name: 'RUN_TESTS',
            defaultValue: true,
            description: 'Run tests'
        )
        booleanParam(
            name: 'GENERATE_DOCS',
            defaultValue: true,
            description: 'Generate documentation'
        )
    }
    
    environment {
        APP_VERSION_MAJOR = '1'
        APP_VERSION_MINOR = '0'
        APP_VERSION_PATCH = '0'
    }
    
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Setup Environment') {
            steps {
                sh '''
                    echo "Setting up environment variables"
                    export BUILD_TYPE=${params.BUILD_TYPE}
                    export LOG_LEVEL=${params.LOG_LEVEL}
                    echo "Build type: ${params.BUILD_TYPE}"
                '''
            }
        }
        
        stage('Code Formatting') {
            steps {
                sh 'make format'
            }
        }
        
        stage('Static Analysis') {
            steps {
                sh 'make check'
            }
        }
        
        stage('Build') {
            steps {
                script {
                    if (params.BUILD_TYPE == 'develop') {
                        sh '''
                            echo "Building with debug flags"
                            export CXXFLAGS="-g -O0 -DDEBUG"
                            make build
                        '''
                    } else {
                        sh '''
                            echo "Building with optimization flags"
                            export CXXFLAGS="-O2 -DNDEBUG"
                            make build
                        '''
                    }
                }
            }
        }
        
        stage('Test') {
            when {
                expression { params.RUN_TESTS == true }
            }
            steps {
                sh 'make test'
                junit 'build/tests/test_results.xml'
            }
        }
        
        stage('Documentation') {
            when {
                expression { params.GENERATE_DOCS == true }
            }
            steps {
                sh 'make doc'
                publishHTML([allowMissing: false, 
                           alwaysLinkToLastBuild: false, 
                           keepAll: true, 
                           reportDir: 'build/docs/html', 
                           reportFiles: 'index.html', 
                           reportName: 'Doxygen Documentation', 
                           reportTitles: ''])
            }
        }
        
        stage('Check Dynamic Library') {
            steps {
                sh 'make check-lib'
                sh '''
                    echo "Checking library dependencies:"
                    ldd build/mathlib/libmathlib.so 2>/dev/null || echo "Static check passed"
                '''
            }
        }
        
        stage('Integration Test') {
            steps {
                sh 'make test-integration'
            }
        }
        
        stage('Archive Artifacts') {
            steps {
                archiveArtifacts artifacts: 'build/**/*.so,build/**/client,build/**/server', 
                               fingerprint: true
                archiveArtifacts artifacts: '*.log,config/*.json', 
                               fingerprint: true
            }
        }
    }
    
    post {
        always {
            cleanWs()
        }
        success {
            emailext(
                subject: "Build Successful: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """
                Kenguru Project build successful!
                
                Build: ${env.JOB_NAME} #${env.BUILD_NUMBER}
                Build type: ${params.BUILD_TYPE}
                Status: ${currentBuild.result}
                
                View build: ${env.BUILD_URL}
                """,
                to: 'developer@example.com'
            )
        }
        failure {
            emailext(
                subject: "Build Failed: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """
                Kenguru Project build failed!
                
                Build: ${env.JOB_NAME} #${env.BUILD_NUMBER}
                Build type: ${params.BUILD_TYPE}
                Status: ${currentBuild.result}
                
                View build: ${env.BUILD_URL}
                Check logs for details.
                """,
                to: 'developer@example.com'
            )
        }
    }
}
